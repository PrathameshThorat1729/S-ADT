#include <Array.hpp>
#include <debug.hpp>

Array::Array()
{
  _size = 1;
  _len = 0;

  _arr = new int[_size];
}

Array::Array(int len, int i_val)
{
  _size = 1;
  _len = 0;

  _arr = new int[_size];

  while (len--)
    this->operator<<(i_val);
}

void Array::insert(int _ind, int _el)
{
  if (_len == _size)
  {
    _size *= 2;

    int *ptr = new int[_size];
    for (int i = 0; i < _len; i++)
    {
      ptr[i] = _arr[i];
    }

    delete[] _arr;
    _arr = ptr;
  }

  if (_ind > _len)
    throw std::out_of_range("index is 'out of range' of memory");

  for (int i = _len++; i > _ind; i--)
    _arr[i] = _arr[i - 1];

  _arr[_ind] = _el;
}

void Array::operator<<(int _el)
{
  this->insert(_len, _el);
}

int Array::remove(int _ind)
{
  if (_len == 0)
    throw std::out_of_range("no any item in memory");
    
  if (_ind >= _len--)
    throw std::out_of_range("index is 'out of range' of memory");

  int el = _arr[_ind];

  for (int i = _ind; i <= _len; i++)
  {
    _arr[i] = _arr[i + 1];
  }

  return el;
}

int &Array::operator[](int _ind)
{
  if (_ind >= _len || _ind < 0)
    throw std::out_of_range("index is 'out of range' of memory");

  return _arr[_ind];
}

void Array::traverse(void (*callback)(int, int, Array *, void *), void *any)
{
  for (int i = 0; i < _len; i++)
  {
    callback(i, _arr[i], this, any);
  }
}

void Array::b_sort(bool asc)
{
  int curr;
  for (int i = 0; i < _len - 1; i++)
  {
    for (int j = 0; j < _len - 1 - i; j++)
    {
      if (_arr[j] > _arr[j + 1])
      {
        curr = _arr[j];
        _arr[j] = _arr[j + 1];
        _arr[j + 1] = curr;
      }
    }
  }
}

void Array::s_sort(bool asc)
{
  int min = _arr[0];
  for (int i = 0; i < _len; i++)
  {
    for (int j = i + 1; j < _len; j++)
    {
      if (_arr[i] < _arr[j] && !asc)
      {
        min = _arr[j];
        _arr[j] = _arr[i];
        _arr[i] = min;
      }
      else if (_arr[i] > _arr[j] && asc)
      {
        min = _arr[j];
        _arr[j] = _arr[i];
        _arr[i] = min;
      }
    }
  }
}

void Array::i_sort(bool asc)
{
  for (int i = 1; i < _len; i++)
  {
    for (int j = i; j > 0; j--)
    {
      if (asc)
      {
        if (_arr[j] < _arr[j-1])
        {
          int curr = _arr[j];
          _arr[j] = _arr[j-1];
          _arr[j-1] = curr;
        }
      }
      else
      {
        if (_arr[j] > _arr[j-1])
        {
          int curr = _arr[j];
          _arr[j] = _arr[j-1];
          _arr[j-1] = curr;
        }
      }
    }
  }
}

int Array::l_search(int _el)
{
  for (int i = 0; i < _len; i++)
  {
    if (_arr[i] == _el)
      return i;
  }

  return -1;
}

int Array::b_search(int _el, bool is_sorted, bool asc)
{
  if (!is_sorted)
    this->b_sort(asc);

  int i = 0;
  int j = _len - 1;
  int mid;

  while (i <= j)
  {
    mid = (i + j) / 2;
    if (_arr[mid] == _el)
      return mid;

    if (_arr[mid] > _el)
    {
      if (asc)
        j = mid - 1;
      else
        i = mid + 1;
    }

    else if (_arr[mid] < _el)
    {
      if (asc)
        i = mid + 1;
      else
        j = mid - 1;
    }
  }

  return -1;
}

int Array::size()
{
  return this->_size;
}

int Array::length()
{
  return this->_len;
}

bool Array::empty()
{
  if (_len > 0)
    return false;
  return true;
}

Array::~Array()
{
  delete[] _arr;
}