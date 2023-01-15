#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    deque<char> dq;
    deque<char> sub_dq;
    deque<char> ans;
    unordered_set<char> st;
    int mx = -1;

    for (auto el : s)
        dq.emplace_back(el);

    for (char el : dq)
    {
        sub_dq.emplace_back(el);
        st.emplace(el);

        for (auto el : sub_dq)
            cerr << el;
        cerr << endl;

        while (sub_dq.size() != st.size()) // repeating element
        {
            for (auto el : sub_dq)
                cerr << el << "__";
            cerr << " : ";

            if (sub_dq.front() != el) // only if el is not 'front'    // Edge-case: "xcabcdefac"
            {
                st.erase(sub_dq.front());
            }
            sub_dq.pop_front();

            for (auto el : sub_dq)
                cerr << el << "__";
            cerr << endl;
        }

        int len = sub_dq.size();
        if (len > mx)
        {
            mx = len;
            ans = sub_dq;
        }
    }

    cerr << "ans: ";
    for (auto el : ans)
        cerr
            << el;
    cerr << endl;

    cout << mx;

    return 0;
}