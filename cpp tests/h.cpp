#include <bits/stdc++.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
#include <numeric>

using namespace std;
#define endl "\n"
#define ll long long

unsigned long long int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unsigned long long int f = 1;
    for (int i = 0; i < n; i++)
    {
        f *= i;
    }

    // unsigned long long int f = fact(n);
    cerr << f << endl;
    string str = to_string(f);
    auto cnt = str.size();
    reverse(str.begin(), str.end());
    cerr << str << endl;

    auto tmp = stoll(str);

    str = to_string(tmp);
    cerr << str << endl;
    cout << cnt - str.size() << endl;

    return 0;
}
