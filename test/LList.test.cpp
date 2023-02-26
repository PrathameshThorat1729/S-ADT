#include <iostream>
#include <LList.hpp>
#include <conio.h>
using namespace std;

int main()
{
    LList list;

    cout << "Adding 10 nums ..." << endl;
    for (int i = 1; i <= 10; i++)
        list << i;

    cout << "size : " << list.size() << endl;
    cout << endl;

    // for (int i = 0; i < 5; i++)
    list.remove(0);

    cout << "size : " << list.size() << endl;
    cout << endl;

    cout << "size : " << list.size() << endl;
    cout << endl;

    list.remove(4);

    cout << "size : " << list.size() << endl;
    cout << endl;

    Node *nd = list.at(4);
    cout << nd << " " << nd->next << " " << nd->value << endl;

    return 0;
}