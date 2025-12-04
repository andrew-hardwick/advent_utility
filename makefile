all: build
	meson compile -C build

build:
	meson setup build

runtest: all
	meson test -C build

clean:
	rm -rf build
	rm -rf result

