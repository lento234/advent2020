all: config build run

MAIN=day06

config:
	cmake -B build

build:
	make -C build

run:
	cd build && ./$(MAIN)

clean:
	$(RM) -rvf build

.PHONY: all clean run build config
