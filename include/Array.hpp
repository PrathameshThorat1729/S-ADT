#ifndef SADT_ARRAY
#define SADT_ARRAY

#include <stdexcept>

class Array {
private:
  int* _arr;
  int _size;

public:
  Array(int);
  int at(int);
  bool at(int, int);
  void traverse(void (*)(int,int,Array*, void*), void*);
  void b_sort();
  int size();
  ~Array();
};

#endif