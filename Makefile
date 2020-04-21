all: main.o GeneralQueue.o GeneralStack.o GeneralList.o
	g++ GeneralStack.o GeneralQueue.o GeneralList.0 main.o -o TEST_MEOW

GeneralList.o: GeneralList.hpp main.o
	g++ -c GeneralList.hpp

GeneralQueue.o: GeneralQueue.hpp main.o
	g++ -c GeneralQueue.hpp

GeneralStack.o: GeneralStack.hpp main.o
	g++ -c GeneralStack.hpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o
	rm TEST_MEOW

