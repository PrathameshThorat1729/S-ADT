#include <LList.hpp>

////////// Node Class ///////////

Node::Node()
{
  next = nullptr;
}

Node::Node(int el)
{
  value = el;
  next = nullptr;
}

////////// Linked List Class ///////////

LList::LList()
{
  _head = nullptr;
  _size = 0;
}

void LList::insert(int _ind, int _el)
{
  if (_ind > _size)
    throw std::out_of_range("index is 'out of range' of memory");

  if (_size++ == 0)
  {
    _head = new Node(_el);
    return;
  }

  Node *curr = new Node;
  curr->next = _head;

  int i = 0;
  while (curr->next != nullptr && i < _ind)
  {
    curr = curr->next;
    i++;
  }

  Node *new_node = new Node(_el);
  new_node->next = curr->next;
  curr->next = new_node;
}

void LList::operator<<(int _el)
{
  this->insert(_size, _el);
}

int LList::remove(int _ind)
{
  if (_ind >= _size)
    throw std::out_of_range("index is 'out of range' of memory");

  _size--;

  if (_ind == 0)
  {
    Node *to_del = _head;
    int val = to_del->value;
    _head = _head->next;

    delete to_del;

    return val;
  }

  Node *curr = new Node;
  curr->next = _head;

  int i = 0;
  while (curr->next != nullptr && i < _ind)
  {
    curr = curr->next;
    i++;
  }

  Node *to_del = curr->next;
  curr->next = to_del->next;

  int val = to_del->value;
  delete to_del;

  return val;
}

Node *LList::at(int _ind)
{
  if (_ind > _size)
    throw std::out_of_range("index is 'out of range' of memory");

  Node *curr = new Node;
  curr->next = _head;

  int i = 0;
  while (curr->next != nullptr && i < _ind)
  {
    curr = curr->next;
    i++;
  }

  return curr->next;
}

int &LList::operator[](int _ind)
{
  if (_ind > _size)
    throw std::out_of_range("index is 'out of range' of memory");

  Node *curr = new Node;
  curr->next = _head;

  int i = 0;
  while (curr->next != nullptr && i <= _ind)
  {
    curr = curr->next;
    i++;
  }

  return curr->value;
}

int LList::size()
{
  return _size;
}