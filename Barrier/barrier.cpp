
#include "Semaphore.h"
#include <iostream>
#include <thread>

int count = 0;
int noThreads = 3;

void barrier_trans(std::shared_ptr<Semaphore> mutex,std::shared_ptr<Semaphore> turnstile,std::shared_ptr<Semaphore> turnstile2){
  while(true){
    std::cout << "OPEN 1" << " TID: " << std::this_thread::get_id() << std::endl;
    mutex->Wait();
    count++;
    if(count == noThreads){
      turnstile2->Wait();
      turnstile->Signal();
      std::cout << "TURNSTILE 2 OPEN <---> TURNSTILE 1 CLOSED <---> COUNT = " << count << std::endl;
    }
    mutex->Signal();

    turnstile->Wait();
    turnstile->Signal();

    std::cout << "OPEN 2 " << " TID: " << std::this_thread::get_id() << std::endl;

    mutex->Wait();
    count--;
    if(count == 0){
      turnstile->Wait();
      turnstile2->Signal();
      std::cout << "TURNSTILE 1 OPEN <---> TURNSTILE 2 CLOSED <---> COUNT = " << count << std::endl;
    }
    //mutex->Signal()
    turnstile2->Wait();
    turnstile2->Signal();
  }
}

int main(void){

  std::thread threadOne, threadTwo, threadThree;
  std::shared_ptr<Semaphore> mutex( new Semaphore(1) );
  std::shared_ptr<Semaphore> turnstile( new Semaphore);
  std::shared_ptr<Semaphore> turnstile2( new Semaphore(1));

  threadOne=std::thread(barrier_trans,mutex,turnstile,turnstile2);
  threadTwo=std::thread(barrier_trans,mutex,turnstile,turnstile2);
  threadThree=std::thread(barrier_trans,mutex,turnstile,turnstile2);

  threadOne.join();
  threadTwo.join();
  threadThree.join();

  return 0;
}
