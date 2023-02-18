#include <Stack.hpp>

int Stack::top()
{
  return _arr[_len - 1];
}

void Stack::push(int _el)
{
  this->operator<<(_el);
}

int Stack::pop()
{
  return this->remove(_len - 1);
}