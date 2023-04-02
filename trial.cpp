#include <bits/stdc++.h>
using namespace std;

int foo()
{
    int a = 90;

    return a = 999;
}

int main()
{
    cout << foo();
}