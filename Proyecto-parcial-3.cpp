#include "Fecha.h"
#include <iostream>
using namespace std;
int main()
{
    Fecha f1(30, 12, 1999);
    Fecha f2(30,12,1999);
    if (f1==f2)
    {
        cout << "si";
    }
    else
    {
        cout << "no";
    }
    return 0;
}
