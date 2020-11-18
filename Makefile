.DEFAULT_GOAL: build

N_CPU ?= $(shell grep -c "^processor" /proc/cpuinfo)

build:
	@mkdir -p build && cd build && cmake .. && make -j$(N_CPU)

clean:
	@rm -fr build

info:
	@echo Building with $(N_CPU) cores

play:
	@./build/Src/ttt-plusplus