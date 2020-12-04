all: build run

BIN=day02

build:
	cmake -H. -B build
	make -C build
	cp -v build/$(BIN) .
	@echo ""

run:
	./$(BIN)

clean:
	$(RM) -rvf build
	$(RM) $(BIN)

.PHONY: all clean run build
