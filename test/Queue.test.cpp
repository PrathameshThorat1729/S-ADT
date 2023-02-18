#include <iostream>
#include <Queue.hpp>
using namespace std;

int main()
{
  Queue que;

  for (int i = 1; i <= 5; i++)
    que.enqueue(i);
  
  cout << "Front : " << que.front() << ", Rear : " << que.rear() << endl;
  cout << "size : " << que.size() << ", length : " << que.length() << endl;
   
  for (int i = 6; i <= 10; i++)
    que << i;
    
  cout << "\nFront : " << que.front() << ", Rear : " << que.rear() << endl;
  cout << "size : " << que.size() << ", length : " << que.length() << endl;
  
  cout << endl;
  for (int i = que.length(); i > 0; i--)
    cout << que.dequeue() << " Dequeued"<< endl;
  
  cout << "\nsize : " << que.size() << ", length : " << que.length() << endl;
  
  return 0;
}