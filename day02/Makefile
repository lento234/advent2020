all: build run

build:
	cmake -H. -B build
	make -C build
	cp -v build/main .
	@echo ""

run:
	./main

clean:
	$(RM) -rvf build
	$(RM) main 

.PHONY: all clean run build
