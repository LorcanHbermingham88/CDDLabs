#Lorcan Bermingham 03/10/2017
#makefile

Signal: Semaphore.h Semaphore.cpp signal.cpp
				g++ -std=c++11 -pthread -o Run Semaphore.cpp signal.cpp Semaphore.h


#this is customary and just deletes all .o files
CLEAN:
	rm *.o
