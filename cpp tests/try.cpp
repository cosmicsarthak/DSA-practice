#include <bits/stdc++.h>
using namespace std;

vector<int> cap(3);
vector<int> am(3);

void sol(int a, int b)
{
    int x = min(cap.at(b) - am.at(b), am.at(a));
    am.at(a) -= x;
    am.at(b) += x;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tmp;
    for (int i = 0; i < 3; i++)
    {
        cin >> tmp;
        cap.at(i) = tmp;
        cin >> tmp;
        am.at(i) = tmp;
    }

    for (int i = 0; i < 100; i++)
    {
        sol(i % 3, (i + 1) % 3);
    }

    for (auto el : am)
    {
        cout << el << endl;
    }

    return 0;
}