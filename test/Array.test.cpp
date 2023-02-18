#include <iostream>
#include <cstdlib>
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
  srand(time(0));
  int sum = 0;
  Array arr;

  cout << "Adding from 10 random nums ..." << endl;
  for (int i = 1; i <= 10; i++)
  {
    arr << (rand() % 91) + 10;
  }

  cout << "size : " << arr.size() << ", length : " << arr.length() << endl;
  print_arr(&arr);

  cout << "at 4 : " << arr[4] << endl;
  arr[4] = (rand() % 91) + 10;
  cout << "now at 4 : " << arr[4] << endl;
  print_arr(&arr);

  int to_ins = (rand() % 91) + 10;
  cout << "inserting " << to_ins << " at 6 ..." << endl;
  arr.insert(6, to_ins);
  cout << "size : " << arr.size() << ", length : " << arr.length() << endl;
  print_arr(&arr);

  cout << "removing element at 7 ... " << arr.remove(7) << endl;
  cout << "size : " << arr.size() << ", length : " << arr.length() << endl;
  print_arr(&arr);

  cout << "traverse to get sum : ";
  arr.traverse(get_sum, &sum);
  cout << sum << endl;

  bool asc = false;
  // arr.b_sort(asc);
  // arr.s_sort(asc);
  arr.i_sort(asc);
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