CC := clang --target=wasm32-unknown-none-wasm
CPPFLAGS := -MMD -MP
CFLAGS := -pipe -Iinclude -O3 -Wall -flto
LDFLAGS := -nostdlib -fno-lto

metallic.a: metallic.bc
	llc -filetype=obj -o $@ $^

metallic.bc: $(patsubst %.c, %.o, $(filter-out test/%, $(wildcard */*.c */*/*.c)))
	llvm-link $^ | opt -mergefunc -std-link-opts -o $@

check: test/index.mjs $(patsubst %.c, %.out, $(wildcard test/*.c test/*/*.c))
	node --experimental-modules $^

test/%.out: metallic.a test/%.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.bc *.a */*.o */*/*.o */*.d */*/*.d test/*.out

-include */*.d */*/*.d
