#ifndef SADT_STACK
#define SADT_STACK

#include <Array.hpp>
#include <stdexcept>

class Stack : public Array
{
private:
  using Array::insert;
  
  using Array::remove;
  
  using Array::traverse;

  using Array::b_sort;
  using Array::s_sort;
  using Array::i_sort;

  using Array::l_search;
  using Array::b_search;

public:
  int top();
  void push(int);
  int pop();
  int search(int);
};

#endif