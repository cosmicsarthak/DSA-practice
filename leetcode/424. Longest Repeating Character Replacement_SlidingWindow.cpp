#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

// 3 edge cases
// i. taking 1st char and replacing next k char
// ii. reverse and then taking 1st char & replacing next k char
// ii. 1st and last both have to be changed
// iii. if k digits have not been replaced, then check in circular form or (if and last are same)

// SLIDING WINDOW
// ABCCDC

int characterReplacement(string s, int k)
{
    vector<char> v;
    for (auto &el : s)
        v.emplace_back(el);
    unordered_map<char, int> mp;

    // index
    int window_start = 0, window_size = 0, n = v.size(), mx = -1;
    deque<int> subV;
    deque<int> ans;
    for (int i = 0; i < n; i++) // for vector `v`
    {
        subV.emplace_back(v.at(i));
        ++mp[v.at(i)];
        int freq = 0;
        char highest_freq; // others to be replaced by it
        for (auto el : mp)
        {
            if (el.second >= freq)
            {
                freq = el.second;
                highest_freq = el.first;
            }
        }

        while (mp.size() > k)
        {
            char el = subV.at(window_start);
            --mp[el];
            if (mp[el] == 0)
            {
                mp.erase(el);
            }
            subV.erase(subV.begin() + window_start);
            ++window_start;
        }

        if (mp.size() == k + 1) // k+1 as k char to be replaced & 1 for the character which stays contant
        {
            subV.back() = highest_freq;
            if (subV.size() > mx)
            {
                mx = subV.size();
                ans = subV; // both are deque
            }
        }
    }
}

int main()
{
    int ans = characterReplacement("ABBB", 2);

    cout << ans << endl;
}