all:
	cmake -H. -B build
	make -C build
	cp -v build/main .

run:
	./main

clean:
	$(RM) -rvf build
	$(RM) main 

.PHONY: all clean run
