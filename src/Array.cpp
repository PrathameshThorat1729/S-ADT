#include <Array.hpp>

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

int Array::size ()
{
  return this->_size;
}

Array::~Array ()
{
  delete[] _arr;
}