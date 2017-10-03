#Lorcan Bermingham 03/10/2017
#Makefile

Signal: Semaphore.h Semaphore.cpp signal.cpp
				g++ -std=c++11 -pthread -o Run Semaphore.cpp signal.cpp Semaphore.h

CLEAN:
	rm -f *.o
