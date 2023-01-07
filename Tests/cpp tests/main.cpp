#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<int> st;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        st.emplace(tmp);
    }

    cout << st.size();

    return 0;
}