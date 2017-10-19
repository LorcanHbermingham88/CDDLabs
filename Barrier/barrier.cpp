#include "Semaphore.h"
#include <iostream>
#include <thread>

int count = 0;

void taskOne(std::shared_ptr<Semaphore> theSemaphore){

}
int main(void){
  std::thread threadOne;
  std::shared_ptr<Semaphore> mutex(new Semaphore);
  std::shared_ptr<Semaphore> barrier1(new Semaphore);

  threadOne=std::thread(taskOne,sem);
  //threadTwo=std::thread(taskOne,sem,sem2);
  std::cout << "Launched from the main\n";
  threadOne.join();
  //threadTwo.join();
  return 0;
}

//std::shared_ptr<Semaphore> sem2
