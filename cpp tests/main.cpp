#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tmp1, tmp2;

    cin >> tmp1 >> tmp2;
    pair<int, int> pr1 = {tmp1, tmp2};
    cin >> tmp1 >> tmp2;
    pair<int, int> pr2 = {tmp1, tmp2};
    cin >> tmp1 >> tmp2;
    pair<int, int> pr3 = {tmp1, tmp2};

    for (int i = 0; i <= 100; i++)
    {
        if (pr1.second >= pr2.first - pr2.second)
        {
            pr1.second -= pr2.first - pr2.second;
            // pr2.second += pr2.first - pr2.second;
            pr2.second = pr2.first;
        }

        else
        {
            pr2.second += pr1.second;
            pr1.second = 0;
        }
        if (pr2.second >= pr3.first - pr3.second)
        {
            pr2.second -= pr3.first - pr3.second;
            // pr3.second += pr3.first - pr3.second;
            pr3.second = pr3.first;
        }
        else
        {
            pr3.second += pr2.second;
            pr2.second = 0;
        }
        if (pr3.second >= pr1.first - pr1.second)
        {
            pr3.second -= pr1.first - pr1.second;
            // pr1.second += pr1.first - pr1.second;
            pr1.second = pr1.first;
        }
        else
        {
            pr1.second += pr3.second;
            pr3.second = 0;
        }
    }

    cout << pr1.second << endl
         << pr2.second << endl
         << pr3.second << endl;

    return 0;
}