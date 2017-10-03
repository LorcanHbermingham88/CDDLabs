#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;   //you can use std::lock_guard if you want to be exception safe
int i = 0;

void taskOne(std::shared_ptr<Semaphore> theSemaphore1, std::shared_ptr<Semaphore> theSemaphore2){
  m.lock();
  std::cout <<"ONE"<<std::endl;
  i++;
  m.unlock();
}
void taskTwo(std::shared_ptr<Semaphore> theSemaphore1, std::shared_ptr<Semaphore> theSemaphore2){
  m.lock();
  std::cout <<"FIVE "<<std::endl;
  i++;
  m.unlock();
}
int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem1( new Semaphore);
  std::shared_ptr<Semaphore> sem2( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem1,sem2);
  threadTwo=std::thread(taskOne,sem1,sem2);
  std::cout << "Launched from the main  \n\n"<<std::endl;
  threadOne.join();
  threadTwo.join();
  return 0;
}
