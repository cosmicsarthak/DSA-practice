#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

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
    int k;
    cin >> k;
    int n = v.size();

    int window_size = 0, window_sum = 0, window_start = 0;
    int mx = 0;
    int ans_st;
    int ans_end;
    vector<int> ans;
    for (int window_end = 0; window_end < n; window_end++)
    {
        ++window_size;
        window_sum += v.at(window_end);

        if (window_size > k)
        {
            window_sum -= v.at(window_start);
            ++window_start;
            if (window_sum > mx)
            {
                mx = window_sum;
                ans_st = window_start; // ans starting index
                ans_end = window_end;  // ans ending index
            }
        }
    }

    for (int i = ans_st; i <= ans_end; i++)
        ans.emplace_back(v.at(i));

    cout << mx << endl;
    for (auto &el : ans)
        cerr << el << " ";

    return 0;
}