#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool valid(string &s)
{
    int balance = 0;
    for (auto &el : s)
    {
        if (el == '(')
            ++balance;
        else
            --balance;
        if (balance < 0)
            return false;
    }
    return (balance == 0);
}

vector<int> ls;

int main()
{
    if (ls.empty())
    {
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    vector<string> ans;

    for (int i = 0; i < n; i++)
        s.push_back('(');
    for (int i = 0; i < n; i++)
        s.push_back(')');

    do
    {
        if (valid(s))
        {
            ans.emplace_back(s);
        }
        cerr << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    for (auto el : ans)
        cout << el << " ";

    return 0;
}