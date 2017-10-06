#Lorcan Bermingham 03/10/2017
#Makefile

CC=g++
CFLAGS= -std=c++11 -pthread

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

Signal: Semaphore.h Semaphore.cpp signal.cpp

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o

	# ask about
	#Signal: Semaphore.h Semaphore.cpp signal.cpp
	#g++ -std=c++11 -pthread -o Run Semaphore.cpp signal.cpp Semaphore.h



	DEBUG: DEBUGFLAGS = -DDEBUG
	DEBUG: ALL
