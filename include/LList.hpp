#ifndef SADT_LLIST
#define SADT_LLIST

#include <debug.hpp>
#include <stdexcept>

////////// Node Class ///////////

class Node
{
public:
  Node();
  Node(int);

  int value;
  Node *next;
};

////////// Linked List Class ///////////

class LList
{
private:
  Node *_head;
  int _size;

public:
  LList();
  LList(int);

  void insert(int, int);
  void operator<<(int);

  int remove(int);

  Node *at(int);
  int &operator[](int);

  int size();
};

#endif