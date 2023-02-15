#include <iostream>
#include <Array.hpp>
using namespace std;

void print_arr (Array* arr)
{
  cout << "Arr : ";
  for (int i = 0; i < arr->size(); i++)
    cout << arr->at(i) << " ";
  cout << endl;
}

void get_sum(int ind, int el, Array* arr, void* sum)
{
  int* s = (int*) sum;
  *s += el;
}

int main ()
{
  int sum = 0;
  Array arr(10);
  
  cout << "Adding from 1..10" << endl;
  for (int i = 1; i <= 10; i++)
  {
    arr.at(i - 1, i);
  }
  print_arr(&arr);
  
  cout << "size : " << arr.size() << endl;
  
  cout << "at 4 :" << arr.at(4) << endl;
 
  arr.at(4, 45);
  cout << "now at 4 :" << arr.at(4) << endl;
  
  print_arr(&arr);
  
  cout << "traverse to get sum : ";
  arr.traverse(get_sum, &sum);
  cout << sum << endl;
  
  arr.b_sort();
  print_arr(&arr);
  
  for (int i = -5; i <= arr.size() + 5; i++)
    cout << i << " : " << arr.l_search(i) << " / " << arr.b_search(i, true) << endl;
  
  return 0;
}