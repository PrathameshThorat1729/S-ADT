#include <Stack.hpp>

int Stack::top()
{
  return this->operator[](_len - 1);
}

void Stack::push(int _el)
{
  this->operator<<(_el);
}

int Stack::pop()
{
  return this->remove(_len - 1);
}

int Stack::search(int _el)
{
  return _len - 1 - this->l_search(_el);
}