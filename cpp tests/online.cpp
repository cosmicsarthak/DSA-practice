#include <bits/stdc++.h>

using namespace std;

void cal(string s)
{
    deque<char> dq;
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            res.push_back(s[i]);
        }
        else if (dq.empty())
        {
            dq.emplace_back(s[i]);
        }
        else if (s[i] == '(')
        {
            dq.emplace_back(s[i]);
        }
        else if (s[i] == ')')
        {
            while (dq.back() != '(')
            {
                res.push_back(dq.back());
                dq.pop_back();
            }
            dq.pop_back();
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            if (dq.back() == '*' || dq.back() == '/')
            {
                res.push_back(dq.back());
                dq.pop_back();
                dq.emplace_back(s[i]);
            }
            else
            {
                dq.emplace_back(s[i]);
            }
        }
        else if (s[i] == '*')
        {
            if (dq.back() != '/')
            {
                dq.emplace_back(s[i]);
            }
            else
            {
                res.push_back(dq.back());
                dq.pop_back();
                dq.emplace_back(s[i]);
            }
        }
        else if (s[i] == '/')
        {
            if (dq.back() != '*')
            {
                dq.emplace_back(s[i]);
            }
            else
            {
                res.push_back(dq.back());
                dq.pop_back();
                dq.emplace_back(s[i]);
            }
        }
    }

    for (auto el : dq)
    {
        cerr << el << " ";
    }
    cerr << endl;

    while (!dq.empty())
    {
        res.push_back(dq.back());
        dq.pop_back();
    }

    cout << res << endl;
}
