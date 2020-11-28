build: ./graph.c
	gcc ./graph.c  -c -o graph

valgrind: run
	valgrind --leak-check=full --show-leak-kinds=all  ./graph

test_run: cb
	./test/cb_test

cb: build
	gcc ./test/create_basics.c -g -o ./test/cb_test


