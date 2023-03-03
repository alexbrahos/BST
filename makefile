runMe: main.o Tree.o Node.o
	g++ main.o Tree.o Node.o -o runMe
main.o: main.cpp Tree.h Node.h
	g++ -c main.cpp
Tree.o: Tree.cpp Tree.h Node.h
	g++ -c Tree.cpp
Node.o: Node.cpp Node.h
	g++ -c Node.cpp
run: runMe
	./runMe
clean:
	rm *.o
	rm runMe
