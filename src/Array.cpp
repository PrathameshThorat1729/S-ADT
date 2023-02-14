#include <Array.hpp>
#include <debug.hpp>

Array::Array (int _len)
{
  _size = _len;

  _arr = new int[_size];
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

int Array::size ()
{
  return this->_size;
}

Array::~Array ()
{
  delete[] _arr;
}