#include "Semaphore.h"
#include <iostream>
#include <thread>
//T1
void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout <<"I "<<std::endl;
  std::cout << "must "<<std::endl;
  std::cout << "print "<<std::endl;
  std::cout << "first\n"<<std::endl;
  theSemaphore->Signal();
}
//T2
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This "<<std::endl;
  std::cout << "will "<<std::endl;
  std::cout << "appear "<<std::endl;
  std::cout << "second\n"<<std::endl;
  theSemaphore->Signal();
}
//T3
void taskThree(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This "<<std::endl;
  std::cout << "will "<<std::endl;
  std::cout << "appear "<<std::endl;
  std::cout << "Third\n"<<std::endl;
  theSemaphore->Signal();
}
//T4
void taskFour(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This "<<std::endl;
  std::cout << "is "<<std::endl;
  std::cout << "a "<<std::endl;
  std::cout << "magic "<<std::endl;
  std::cout << "Thread \n"<<std::endl;
}
int main(void){
  std::thread threadOne, threadTwo, threadThree, threadFour;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem);
  threadThree=std::thread(taskThree,sem);
  threadFour=std::thread(taskFour,sem);

  std::cout << "Launched from the main\n\n";
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  threadFour.join();
  return 0;
}
