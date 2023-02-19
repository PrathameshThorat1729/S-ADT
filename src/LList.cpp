#include <LList.hpp>

Node::Node()
{
  _next = null;
}

Node::Node(int _el)
{
  _val = _el;
  _next = null;
}

int &Node::value()
{
  return _val;
}

Node* Node::next()
{
  return next;
}