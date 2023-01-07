/*
Given a string, find the length of the longest substring in it with no more than K distinct characters.

Example 1:

Input: String="araaci", K=2
Output: 4
Explanation: The longest substring with no more than '2' distinct characters is "araa".
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int k;
    cin >> s >> k;

    unordered_map<char, int> mp;

    // index values
    int window_start = 0, window_size = 0;
    string sub_str = "", ans;
    int mx = 0;

    for (int window_end = 0; window_end < s.size(); window_end++)
    {

        if ((mp.count(s.at(window_end)) != 0) || ((mp.count(s.at(window_end)) == 0) && (mp.size() < k)))
        {
            sub_str.push_back(s.at(window_end));
            ++mp[s.at(window_end)];
            ++window_size;
            if (mx < window_size)
            {
                mx = window_size;
                ans = sub_str;
            }
        }
        else // map size is more    // map don't have that element
        {
            sub_str.push_back(s.at(window_end));
            ++mp[s.at(window_end)];
            ++window_size;

            while (mp.size() > k) // removing one unique element
            {
                --mp[sub_str.at(0)];
                if (mp[sub_str.at(0)] == 0)
                {
                    mp.erase(sub_str.at(0));
                }

                sub_str.erase(sub_str.begin()); // iterator to first elment of the substring
                ++window_start;
                --window_size;
            }

            if (mx < window_size)
            {
                mx = window_size;
                ans = sub_str;
            }
        }
    }

    cout << mx << " .. " << ans << endl;
    return 0;
}
