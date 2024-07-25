#include <bits/stdc++.h>
using namespace std;

class Rect
{
public:
    int b;
    int l;
    void area()
    {
        cout << l * b << endl;
    }

    Rect() // default constructor
    {
        l = 10;
        b = 90;
    }
    Rect(int x, int y) // parameterised constructor
    {
        l = x;
        b = y;
    }
    Rect(Rect &r) // copy constructor
    {
        l = 13230;
        b = 2312;
    }
};

int main()
{
    Rect r1;
    // r1.b = 23;
    // r1.l = 100;
    r1.area();

    Rect r2(88, 10);
    r2.area();

    Rect r3 = r2;
    r3.area();

    return 0;
}