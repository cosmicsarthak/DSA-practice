#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

// 3 edge cases
// i. taking 1st char and replacing next k char
// ii. reverse and then taking 1st char & replacing next k char
// ii. 1st and last both have to be changed
// iii. if k digits have not been replaced, then check in circular form or (if and last are same)

int characterReplacement(string s, int k)
{
    int n = s.size();
    string ans;
    int mx = -1;

    // i. taking 1st char and replacing next k char
    for (int i = 0; i < n; i++)
    { // current order of string
        string sub_str = "";
        char alternative = s.at(i);
        int tmp_k = k, j = i;
        while (tmp_k && j < n)
        { // converting next elements to current element
            if (alternative != s.at(j))
            {
                sub_str.push_back(alternative);
                --tmp_k;
            }
            else
            {
                sub_str.push_back(s.at(j));
            }
            ++j;
            cout << sub_str << "__";
        }
        while (j < n && alternative == s.at(j))
        { // normal checking for dupli. chars
            sub_str.push_back(s.at(j));
            ++j;
            cout << sub_str << "..";
        }
        cout << endl;
        int tmp = sub_str.size(); // as str.size() is unsigned type so -1 will be converted to some big +ve no.
        if (tmp > mx)
        {
            mx = sub_str.size();
            ans = sub_str;
        }
    }
    cout << endl;

    // ii. 1st and last both have to be changed
    string revs = s;
    reverse(revs.begin(), revs.end());
    for (int i = 0; i < n; i++)
    { // current order of string
        string sub_str = "";
        char alternative = revs.at(i);
        int tmp_k = k, j = i;
        while (tmp_k && j < n)
        { // converting next elements to current element
            if (alternative != revs.at(j))
            {
                sub_str.push_back(alternative);
                --tmp_k;
            }
            else
            {
                sub_str.push_back(revs.at(j));
            }
            ++j;
            cout << sub_str << " ";
        }
        while (j < n && alternative == revs.at(j))
        {
            sub_str.push_back(revs.at(j));
            ++j;
            cout << sub_str << ",,";
        }
        cout << endl;
        int tmp = sub_str.size(); // as str.size() is unsigned
        if (tmp > mx)
        {
            mx = sub_str.size();
            ans = sub_str;
        }
    }

    cout << endl;
    cout << endl;
    // "ABBBA"
    // iii. if k digits have not been replaced, then check in circular form
    if (s.at(0) && s.at(n - 1) && k != 0)
    { // k!=0 for eg.. "ABAA"
        string circ = s.substr(1, n - 1);
        circ.push_back(s.at(0));
        for (int i = 0; i < n; i++)
        { // current order of string
            string sub_str = "";
            char alternative = circ.at(i);
            int tmp_k = k, j = i;
            while (tmp_k && j < n)
            { // converting next elements to current element
                if (alternative != circ.at(j))
                {
                    sub_str.push_back(alternative);
                    --tmp_k;
                }
                else
                {
                    sub_str.push_back(circ.at(j));
                }
                ++j;
                cout << sub_str << " ";
            }
            while (j < n && alternative == circ.at(j))
            {
                sub_str.push_back(circ.at(j));
                ++j;
                cout << sub_str << ",,";
            }
            cout << endl;
            int tmp = sub_str.size(); // as str.size() is unsigned
            if (tmp > mx)
            {
                mx = sub_str.size();
                ans = sub_str;
            }
        }
    }

    cout << ans << endl;
    return mx;
}

int main()
{
    int ans = characterReplacement("ABBB", 2);

    cout << ans << endl;
}