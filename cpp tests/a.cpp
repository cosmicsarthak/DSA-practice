#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string s;
    cin >> s;
    deque<char> dq;
    set<char> st;
    int ans = 0;

    for (auto &el : s)
    {
        int isPresent = !(st.find(el) == st.end()); // bool

        // entry
        if (dq.empty())
        {
            dq.emplace_back(el);
            st.emplace(el);
        }
        // matching
        else if (!isPresent)
        {
            st.emplace(el);
            dq.emplace_back(el);
        }
        else if (el == dq.back())
        {
            dq.pop_back();
            // st.erase(isPresent);
        }
        // non-matching
        // exit
        else if (isPresent)
        {
            int ind = find(dq.begin(), dq.end(), el) - dq.begin();
            // cerr << ind << " " << el << " " << dq.at(ind) << endl;
            ans += (dq.size() - 1) - ind;
            dq.erase(dq.begin() + ind);
        }
    }

    cout << ans;

    return 0;
}