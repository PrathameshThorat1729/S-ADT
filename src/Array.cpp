#include <Array.hpp>
#include <debug.hpp>

Array::Array (int _len)
{
  _size = _len;

  _arr = new int[_size];
}

Array::Array (int* _els, int _len, int _from)
{
  _size = _len;
  
  _arr = new int[_size];
  for (int i = _from;i < _size + _from; i++)
  {
    this->at(i - _from, _els[i]);
  }
}

int Array::at (int _ind)
{
  if (_ind > _size - 1)
    throw std::out_of_range("a");
    
  return _arr[_ind];
}

bool Array::at (int _ind, int _el)
{
  if (_ind > _size - 1)
    return false;
  
  _arr[_ind] = _el;
  
  return true;
}

void Array::traverse (void (*callback) (int,int,Array*, void*), void* any)
{
  for (int i = 0; i < _size; i++)
  {
    callback(i, _arr[i], this, any);
  }
}

void Array::b_sort ()
{
  int curr;
  for (int i = 0; i < _size - 1; i++)
  {
    for (int j = 0; j < _size - 1 - i; j++)
    {
      if (_arr[j] > _arr[j+1])
      {
        curr = _arr[j];
        _arr[j] = _arr[j+1];
        _arr[j+1] = curr;
      }
    }
  }
}

int Array::l_search (int _el)
{
  for (int i = 0; i < _size; i++)
  {
    if (_arr[i] == _el)
      return i;
  }
  
  return -1;
}

int Array::b_search (int _el, bool is_sorted)
{
  if (!is_sorted)
    this->b_sort();
    
  int i = 0;
  int j = _size - 1;
  int mid;
  
  while (i <= j)
  {
    mid = (i + j) / 2;
    if (_arr[mid] == _el)
      return mid;
    if (_arr[mid] > _el)
      j = mid - 1;
    else if (_arr[mid] < _el)
      i = mid + 1;
  }
  
  return -1;
}

int Array::size ()
{
  return this->_size;
}

Array::~Array ()
{
  delete[] _arr;
}