#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int n;
vector<vector<int>> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {1, 1, 3};
    sort(nums.begin(), nums.end());

    do
    {
        for (auto &el : nums)
            cout << el << " ";
        cout << endl;
    } while (next_permutation(nums.begin(), nums.end()));

    return 0;
}
