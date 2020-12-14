#include <iostream>
#include <direct.h>
#include <stdlib.h>
#include <windows.h>
#define bucketSize 512
using namespace std;

void bktInput(int a, int b)
{
    if (a > bucketSize)
        cout << "\n\t\tBucket overflow";
    else
    {
        Sleep(500);
        while (a > b)
        {
            cout << "\n\t\t" << b << " bytes outputted.";
            a -= b;
            Sleep(500);
        }
        if (a > 0)
            cout << "\n\t\tLast " << a << " bytes sent\t";
        cout << "\n\t\tBucket output successful";
    }
}
int main()
{
    int op, pktSize;
    cout << "Enter output rate : ";
    cin >> op;
    for (int i = 1; i <= 5; i++)
    {
        Sleep(rand() % 10 + 1);
        pktSize = rand() % 1500 + 1;
        cout << "\nPacket no " << i << "\tPacket size = " << pktSize;
        bktInput(pktSize, op);
    }
    return 0;
}
