.DEFAULT_GOAL: build

N_CPU ?= $(shell grep -c "^processor" /proc/cpuinfo)

build:
	@mkdir -p build && cd build && cmake .. && make -j$(N_CPU)

clean:
	@rm -fr build

info:
	@echo Building with $(N_CPU) cores

play: # Play using the native qt app
	@./build/Src/ttt-plusplus

loader: # Create an exportable qtloader (i.e., ESM+TS compat)
	@wget https://github.com/qt/qtbase/raw/dev/src/plugins/platforms/wasm/qtloader.js
	@patch -p1 < export-qtloader.patch
