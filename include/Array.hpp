#ifndef SADT_ARRAY
#define SADT_ARRAY

#include <stdexcept>

class Array
{
private:
  int *_arr;
  int _size;
  int _len;

public:
  Array();
  Array(int, int);

  int &operator[](int);

  void insert(int, int);
  void operator<<(int);

  int remove(int);

  void traverse(void (*)(int, int, Array *, void *), void *);

  void b_sort(bool);
  void s_sort(bool);

  int l_search(int);
  int b_search(int, bool, bool);

  int size();
  int length();

  ~Array();
};

#endif