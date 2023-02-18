#ifndef SADT_QUEUE
#define SADT_QUEUE

#include <Array.hpp>

class Queue : private Array
{
public:
  using Array::operator<<;
  using Array::size;
  using Array::length;
  using Array::empty;
  
  int front();
  int rear();
  void enqueue(int);
  int dequeue();
};

#endif