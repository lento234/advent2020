all: build run

MAIN=day03

build:
	cmake -H. -B build && make -C build

run:
	cd build && ./$(MAIN)

clean:
	$(RM) -rvf build

.PHONY: all clean run build
