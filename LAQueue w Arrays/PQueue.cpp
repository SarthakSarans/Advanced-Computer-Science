// g++ LaQueue.cpp server.cpp client.cpp lqueue.cpp PQueue.cpp -lpthread

#include "PQueue.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
static int pushCount = 0;
/*
 * Class Priority Queue
 */
PQueue::PQueue() { queue = new str[MAX_SIZE]; }
/*
 * Insert into Priority Queue
 */
void PQueue::push(void *item, int priority) {

  queue[end].data = item;
  queue[end].priority = priority;

  end = (end + 1) % MAX_SIZE;

  // if (((end + 1) % sizeof(queue)) == start) {
  //  return;
  // } else {
  //   end = (end + 1) % sizeof(queue);
  //   queue[end].data = item;
  //   if (start == -1) {
  //     start = 0;
  //   }
  // }
}

/*
 * Delete from Priority Queue
 */
void *PQueue::top() {
  /* Your code here */
  //  if (queue[start].data != nullptr)
  return queue[start].data;
  // else
  // return nullptr;
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop() {
  /* Your code here */

  queue[start].data = nullptr;
  queue[start].priority = 0;
  start = (start + 1) % MAX_SIZE;
}

/*
 * Print Priority Queue
 */
void PQueue::display() {

  /* Your code here */

  /* Use the following out command for the data */
  for (int i = start; i != end; i = (i + 1) % MAX_SIZE) {
    std::cout << queue[i].priority << " " << (char *)queue[i].data << std::endl;
  }
}
