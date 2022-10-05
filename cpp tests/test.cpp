#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

void pr(deque<char> dq)
{
    cerr << "dq: ";
    for (auto el : dq)
    {
        cerr << el << " ";
    }
    cerr << endl;
}
void pro(deque<int> dq)
{
    cerr << "dq: ";
    for (auto el : dq)
    {
        cerr << el << " ";
    }
    cerr << endl;
}

int postfix_to_ans(string &s)
{
    deque<int> dq;
    int res = 0;
    int x;
    string ss;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s.at(i)))
        {
            ss = s.at(i);
            x = stoi(ss);
            dq.emplace_back(x);
        }
        else if (s.at(i) == '+')
        {
            int b = dq.back(); // 2nd element
            dq.pop_back();
            int a = dq.back(); // 1st element
            dq.pop_back();
            dq.emplace_back(a + b);
        }
        else if (s.at(i) == '-')
        {
            int b = dq.back(); // 2nd element
            dq.pop_back();
            int a = dq.back(); // 1st element
            dq.pop_back();
            dq.emplace_back(a - b);
        }
        else if (s.at(i) == '*')
        {
            int b = dq.back(); // 2nd element
            dq.pop_back();
            int a = dq.back(); // 1st element
            dq.pop_back();
            dq.emplace_back(a * b);
        }
        else if (s.at(i) == '/')
        {
            int b = dq.back(); // 2nd element
            dq.pop_back();
            int a = dq.back(); // 1st element
            dq.pop_back();
            dq.emplace_back(a / b);
        }
    }
    if (dq.size() == s.size())
    {
        res = stoi(s);
    }
    else
    {
        res = dq.back();
    }
    return res;
}

int cal(string s)
{
    deque<int> dq;
    int res = 0;
    int x;
    string tmp;
    int a, b;
    bool minus_available = false;

    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s.at(i)))
        {
            tmp = s.at(i);
            x = stoi(tmp);
            dq.emplace_back(x);
            if (minus_available)
            {
                dq.back() *= -1;
                minus_available = false;
            }
        }
        else if (s.at(1) == '-')
        {
            // multiply  -1 to first deque value
            minus_available = true;
        }
        else if ((i != s.size() - 1) && (s.at(i) == '+' || s.at(i) == '-' || s.at(i) == '*' || s.at(i) == '/') && (s.at(i + 1) == '-'))
        {

            if (s.at(i) == '+')
            {
                b = dq.back();
                dq.pop_back();
                a = dq.back();
                dq.pop_back();
                dq.emplace_back((b + a) * -1);
            }
            else if (s.at(i) == '-')
            {
                b = dq.back();
                dq.pop_back();
                a = dq.back();
                dq.pop_back();
                dq.emplace_back(a + b);
            }
            else if (s.at(i) == '*')
            {
                b = dq.back();
                dq.pop_back();
                a = dq.back();
                dq.pop_back();
                dq.emplace_back((a * b) * -1);
            }
            else if (s.at(i) == '/')
            {
                b = dq.back();
                dq.pop_back();
                a = dq.back();
                dq.pop_back();
                dq.emplace_back((a / b) * -1);
            }
            s.pop_back();
        }
        else if (s.at(i) == '+' || s.at(i) == '-' || s.at(i) == '*' || s.at(i) == '/')
        {
            if (s.at(i) == '+')
            {
                b = dq.back(); // 2nd element
                dq.pop_back();
                a = dq.back(); // 1st element
                dq.pop_back();
                dq.emplace_back(a + b);
                cerr << "dq: ";
                pro(dq);
                cerr << endl;
            }
            else if (s.at(i) == '-')
            {
                b = dq.back(); // 2nd element
                dq.pop_back();
                a = dq.back(); // 1st element
                dq.pop_back();
                dq.emplace_back(a - b);
            }
            else if (s.at(i) == '*')
            {
                b = dq.back(); // 2nd element
                dq.pop_back();
                a = dq.back(); // 1st element
                dq.pop_back();
                dq.emplace_back(a * b);
            }
            else if (s.at(i) == '/')
            {
                b = dq.back(); // 2nd element
                dq.pop_back();
                a = dq.back(); // 1st element
                dq.pop_back();
                dq.emplace_back(a / b);
            }
        }
    }

    // -ve

    if (dq.size() == s.size())
    {
        res = stoi(s);
    }
    else
    {
        res = dq.back();
    }

    return res;
}

string infix_to_postfix(string s)
{
    deque<char> dq;
    string resultingString = "";
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s.at(i)))
        {
            resultingString.push_back(s.at(i));
        }
        else if (dq.empty())
        {
            dq.emplace_back(s.at(i));
        }
        else if (s.at(i) == '(')
        {
            dq.emplace_back(s.at(i));
        }
        else if (s.at(i) == ')')
        {
            while (dq.back() != '(')
            {
                resultingString.push_back(dq.back());
                dq.pop_back();
            }
            dq.pop_back();
        }
        else if (s.at(i) == '+' || s.at(i) == '-')
        {
            if (dq.back() == '*' || dq.back() == '/' || dq.back() == '+' || dq.back() == '-')
            {
                resultingString.push_back(dq.back());
                dq.pop_back();
                dq.emplace_back(s.at(i));
            }
            else
            {
                dq.emplace_back(s.at(i));
            }
        }
        else if (s.at(i) == '*' || s.at(i) == '/')
        {
            if (dq.back() == '/' || dq.back() == '*')
            {
                resultingString.push_back(dq.back());
                dq.pop_back();
                dq.emplace_back(s.at(i));
            }
            else
            {
                dq.emplace_back(s.at(i));
            }
        }
    }

    while (!dq.empty())
    {
        resultingString.push_back(dq.back());
        dq.pop_back();
    }
    return resultingString; // the resulting string
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);
    string res = infix_to_postfix(str);
    cerr << res << endl;
    int answer = cal(res);
    // int answer = postfix_to_ans(res);
    cout << answer << endl;

    // int ans = calculate(str);
    // cout << ans;

    // str.erase(remove(str.begin(), str.end(), ' '), str.end());

    // cout << str << endl;

    return 0;
}