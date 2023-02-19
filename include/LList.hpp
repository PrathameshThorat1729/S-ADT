#ifndef SADT_LLIST
#define SADT_LLIST

class Node
{
private:
  int _val;
  Node *_next;

public:
  Node();
  Node(int);
  int &value();
  Node *set_next();
}

class LList
{
private:
  Node* _head;
  int _size;
public:
}

#endif