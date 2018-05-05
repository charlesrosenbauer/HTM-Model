fast:
	clang -O3 src/*.c -o bin/htm

test:
	clang -O0 src/*.c -o bin/htm
