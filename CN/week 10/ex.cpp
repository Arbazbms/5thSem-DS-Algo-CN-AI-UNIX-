#include <iostream>
#include <direct.h> //for delay()
#include <conio.h>  //for getch()
int main()
{
    clrscr();
    int n;
    cout << "Enter the delay (in seconds) you want to make after giving input." << endl;
    cin >> n;
    delay(n * 1000);
    cout << "This has been printed after " << n << " seconds delay";
    getch();
    return 0;
}