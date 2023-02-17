#include <iostream>
#include <assert.h>
#include <Array.hpp>
using namespace std;

void print_arr(Array *arr)
{
  cout << "Arr : ";
  for (int i = 0; i < arr->length(); i++)
    cout << arr->operator[](i) << " ";
  cout << endl
       << endl;
}

void get_sum(int ind, int el, Array *arr, void *sum)
{
  int *s = (int *)sum;
  *s += el;
}

int main()
{
  int sum = 0;
  Array arr;

  cout << "Adding from 1..10" << endl;
  for (int i = 1; i <= 10; i++)
  {
    arr << i;
  }

  cout << "size : " << arr.size() << ", length : " << arr.length() << endl;
  print_arr(&arr);

  cout << "at 4 : " << arr[4] << endl;
  arr[4] = 87;
  cout << "now at 4 : " << arr[4] << endl;
  print_arr(&arr);

  cout << "inserting 63 at 6 ..." << endl;
  arr.insert(6, 63);
  cout << "size : " << arr.size() << ", length : " << arr.length() << endl;
  print_arr(&arr);

  cout << "removing element at 7 ... " << arr.remove(7) << endl;
  cout << "size : " << arr.size() << ", length : " << arr.length() << endl;
  print_arr(&arr);

  cout << "traverse to get sum : ";
  arr.traverse(get_sum, &sum);
  cout << sum << endl;

  bool asc = true;
  // arr.b_sort(asc);
  arr.s_sort(asc);
  cout << "\nSorting Array ..." << endl;
  print_arr(&arr);

  for (int i = -5; i <= arr.size() + 5; i++)
  {
    // cout << "[" << i << "] : " << arr.l_search(i) << " / " << arr.b_search(i, true, asc) << endl;
    assert(arr.l_search(i) == arr.b_search(i, true, asc));
  }
  cout << "All Searching Assertions passed" << endl;

  return 0;
}