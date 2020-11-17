.DEFAULT_GOAL: build

build:
	@mkdir -p build && cd build && cmake .. && make

clean:
	@rm -fr build

play:
	@./build/Src/ttt-plusplus