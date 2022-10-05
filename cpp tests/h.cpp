#include <bits/stdc++.h>
// #include <vector>
// #include <sstream>
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <climits>
// #include <numeric>

using namespace std;
#define endl "\n"
#define ll long long

void p(deque<int> dq)
{
    for (auto el : dq)
    {
        cout << el << " ";
    }
    cout << endl;
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> x;
    for (int i = 0; i < 5; i++)
    {
        int tmp;
        cin >> tmp;
        x.emplace_back(tmp);
    }
    p(x);

    x.back() *= -1;
    x.back() = x.back() * 10 + 78;
    p(x);

    return 0;
}
