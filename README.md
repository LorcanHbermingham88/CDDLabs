CDDLabs

These labs are all done in C++ demonstrating different exercises with multi-threading programming. In each file has Doxygen code for clear documentation. Each file has their own makefile for compiling.
Make file

You can compile each lab by typing in to the terminal in the working directory, 'make -k'. This will compile the code and create and executable.

If you type 'make CLEAN' in to the terminal, the make file will remove all of the object files in the folder.
To run

After the executable is created, type "./" + the executable file name to run the program.
Create Doxygen

First you need to open the Doxyfile and edit OUTPUT_DIRECTORY to the working directory + "/docs" (i.e /home/aaron/Desktop/Wator/docs)

and then INPUT to the working directory (i.e /home/aaron/Desktop/Wator)

If you type 'make DOC' in a terminal in the working directory, the make file will compile the Doxygen code and it will display the Doxygen via Mozilla Firefox.
Lab 1

An Implementation of Threads Using Semaphores

Executable file = signal
Lab 2

An Implementation of a Rendezvous using Semaphores

Executable file = signal
Lab 3

An Implementation of a mutex lock Using Semaphores

Executable file = signal
Lab 4

An Implementation of a barrier Using Semaphores

Executable file = barrier
Lab 5

An Implementation of a producer consumer relationship using Semaphores and a safe buffer

Executable file = ProducerConsumer
