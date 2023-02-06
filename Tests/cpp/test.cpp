#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

int mx = -1e7, ansbeg, ansend;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    istringstream ss(s);
    vector<int> v;
    int tmp;
    while (ss >> tmp)
        v.emplace_back(tmp);
    int sm;
    cin >> sm;
    int n = v.size();

    int sum = 0, wsize = 0, wstart = 0;
    // adding to set
    //  if set > k -> shrink from begin
    set<int> st;
    for (int wend = 0; wend < n; wend++)
    {
        st.emplace();
    }

    cout << mx << endl;

    return 0;
}
