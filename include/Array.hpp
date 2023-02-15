#ifndef SADT_ARRAY
#define SADT_ARRAY

#include <stdexcept>

class Array {
private:
  int* _arr;
  int _size;

public:
  Array(int);
  Array(int* ,int,int);
  
  int at(int);
  bool at(int, int);
  
  void traverse(void (*)(int,int,Array*, void*), void*);
  
  void b_sort();
  
  int l_search(int);
  int b_search(int, bool);
  
  int size();
  
  ~Array();
};

#endif