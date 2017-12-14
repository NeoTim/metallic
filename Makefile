CC := clang -fcolor-diagnostics
TARGET := wasm32-unknown-unknown-wasm
CFLAGS := --target=$(TARGET) -pipe -O3 -Iinclude
LDFLAGS := -nostdlib -Wl,--allow-undefined

metallic.so: $(patsubst %.c, %.o, $(wildcard */*.c */*/*.c))
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	$(RM) *.so */*.o */*/*.o