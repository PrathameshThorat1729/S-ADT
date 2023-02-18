#include <iostream>
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
    
  cout << "\nTop : " << stk.top() << endl;
  cout << "size : " << stk.size() << ", length : " << stk.length() << endl;
  
  cout << endl;
  for (int i = stk.length(); i > 0; i--)
    cout << stk.pop() << " Popped"<< endl;
  
  cout << "\nsize : " << stk.size() << ", length : " << stk.length() << endl;
  
  return 0;
}