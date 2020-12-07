all: config build run

MAIN=day07

config:
	cmake -B build

build:
	make -C build

run:
	cd build && ./$(MAIN)

clean:
	$(RM) -rvf build

.PHONY: all clean run build config
