#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct StructExample
{
    int a(89);
    double b(789.90);
    string x;

    // StructExample() : a(78), b(89.889), x("Constructor") {}
    // StructExample() : a{78}, b{89.889}, x{"Constructor"} {}
    // StructExample()
    // {
    //     a = 78;
    //     b = 89.889;
    //     x = "Brace Constructor";
    // }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // st hell{
    //     45,
    //     90.79, "string"};

    StructExample hell;

    cout << hell.a << endl
         << hell.b << endl
         << hell.x << endl;

    StructExample *ptr = &hell;

    cerr << (*ptr).x << endl;
    cerr << ptr->x << endl;

    return 0;
}