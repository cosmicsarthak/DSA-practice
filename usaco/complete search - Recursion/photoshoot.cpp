#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> ans;
vector<int> b;
map<int, int> mp;

void foo(vector<int> &nums, vector<int> &perm, vector<int> &b)
{
    if (perm.size() == nums.size())
    {
        // perm print
        // for (auto el : perm)
        // {
        //     cout << el;
        // }
        // cout << endl;

        bool flag = true;
        for (int i = 0; i < perm.size() - 1; i++)
        {

            // cerr << perm.at(i) << "+" << perm.at(i + 1) << "__" << b.at(i) << endl;
            if (perm.at(i) + perm.at(i + 1) != b.at(i))
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans = perm;
            return;
        }
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (mp[nums.at(i)] == 0)
        {
            ++mp[nums.at(i)];
            perm.emplace_back(nums.at(i));
            foo(nums, perm, b);
            perm.pop_back();
            --mp[nums.at(i)];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> b(n - 1);
    for (auto &el : b)
    {
        cin >> el;
    }

    vector<int> nums;
    for (int i = 1; i <= n; i++)
    {
        nums.emplace_back(i);
    }

    vector<int> perm;
    foo(nums, perm, b);

    for (int i = 0; i < n - 1; i++)
    {
        cout << ans.at(i) << " ";
    }
    cout << ans.at(n - 1) << endl;

    return 0;
}
