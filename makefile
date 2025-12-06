all: build
	meson compile -C build

build:
	meson setup build -Db_coverage=true -Dc_args=-0g --buildtype=debug

runtest: all
	meson test -C build

coverage: runtest
	ninja coverage-html -C build

clean:
	rm -rf build
	rm -rf result

