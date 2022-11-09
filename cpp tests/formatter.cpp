#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    vector<int> v1(n);
    vector<int> v2(n);

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.at(i).first = tmp;
        v1.at(i) = tmp;
    }
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.at(i).second = tmp;
        v2.at(i) = tmp;
    }

    int max_square = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dis = pow((v1.at(i) - v1.at(j)), 2) + pow((v2.at(i) - v2.at(j)), 2);
            max_square = max(max_square, dis);
        }

        for (int j = i + 1; j < n; j++)
        {
            int dis = pow((v1.at(i) - v1.at(j)), 2) + pow((v2.at(i) - v2.at(j)), 2);
            max_square = max(max_square, dis);
        }
    }

    cout << max_square;
}