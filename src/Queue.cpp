#include <Queue.hpp>

int Queue::front()
{
  return _arr[0];
}
int Queue::rear()
{
  return _arr[_len - 1];
}

void Queue::enqueue(int _el)
{
  this->operator<<(_el);
}

int Queue::dequeue()
{
  return this->remove(0);
}