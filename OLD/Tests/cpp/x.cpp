#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
vector<vector<int>> ans;
unordered_map<int, int> mp; // has map

void foo(vector<int> &nums, vector<int> &perm)
{
    // base
    if (perm.size() == n)
    {
        ans.emplace_back(perm);
    }
    for (int i = 0; i < n; i++)
    {
        if (mp.at(nums.at(i)) != 0)
        {
            perm.emplace_back(nums.at(i));
            --mp.at(nums.at(i));
            foo(nums, perm);
            perm.pop_back();
            ++mp.at(nums.at(i));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {1, 2, 3};
    n = nums.size();
    vector<int> perm;

    for (auto el : nums)
    {
        ++mp[el];
    }

    foo(nums, perm);

    for (auto el : ans)
    {
        cout << "[";
        for (auto el2 : el)
        {
            cout << el2 << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
