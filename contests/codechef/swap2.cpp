#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
vector<vector<int>> ans;
unordered_map<int, int> mp; // has map

void foo(vector<int> &nums, vector<int> &perm)
{
    if (perm.size() == nums.size())
    {
        ans.emplace_back(perm);
        return;
    }

    for (auto &el : mp)
    {
        if (el.second > 0)
        {
            --el.second;
            perm.emplace_back(el.first);
            foo(nums, perm);
            ++el.second;
            perm.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {1, 1, 2};
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
