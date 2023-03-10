#ifndef SADT_STACK
#define SADT_STACK

#include <Array.hpp>

class Stack : private Array
{
public:
  using Array::operator<<;
  using Array::size;
  using Array::length;
  using Array::empty;
  
  int top();
  void push(int);
  int pop();
};

#endif