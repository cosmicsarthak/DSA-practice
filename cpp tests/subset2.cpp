#include <bits/stdc++.h>
using namespace std;

set<vector<int>> ans;
vector<int> sub;

void boo(vector<int> &v, vector<int> &sub, int i)
{
    if (i == v.size())
    {
        // sort(sub.begin(), sub.end());
        ans.emplace(sub);
        return;
    }
    boo(v, sub, i + 1);
    sub.emplace_back(v.at(i));
    boo(v, sub, i + 1);
    sub.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<int> v(nums.begin(), nums.end());
    boo(v, sub, 0);
    vector<vector<int>> sol(ans.begin(), ans.end());

    return sol;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &el : v)
    {
        cin >> el;
    }

    vector<vector<int>> xx = subsetsWithDup(v);

    for (auto el : xx)
    {
        for (auto el2 : el)
        {
            cout << el2 << " ";
        }
        cout << endl;
    }
}
