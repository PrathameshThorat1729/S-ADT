#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <Stack.hpp>
using namespace std;

int main()
{
  Stack stk;

  for (int i = 1; i <= 5; i++)
    stk.push(i);
  
  cout << "Top : " << stk.top() << endl;
  cout << "size : " << stk.size() << ", length : " << stk.length() << endl;
   
  for (int i = 6; i <= 10; i++)
    stk << i;
    
  cout << "4 is at " << stk.search(4) << endl;
  
  cout << "Top : " << stk.top() << endl;
  cout << "size : " << stk.size() << ", length : " << stk.length() << endl;
  
  for (int i = stk.length(); i > 0; i--)
    cout << stk.pop() << " Popped"<< endl;
  
  cout << "size : " << stk.size() << ", length : " << stk.length() << endl;
  
  return 0;
}