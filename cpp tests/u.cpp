#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl '\n'

int postfix_to_answer(string s)
{
    deque<int> dq;
    int res = 0;
    int x;
    string tmp;
    int a, b;
    bool minus_available = false; // to check if (-) is at the beginning
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s.at(i)))
        {
            // tmp = s.at(i);
            // x = stoi(tmp);
            // dq.emplace_back(x);
            dq.emplace_back(s.at(i) - '0');
            if (minus_available)
            {
                dq.back() *= -1;
                minus_available = false;
            }
            // while (((i + 1) < s.size()) && (isdigit(s.at(i + 1))))
            // {
            //     // int number = s.at(i + 1) - '0';
            //     tmp = s.at(i); // converting char to string ; as only string can be conv to int using 'stoi'
            //     int x = dq.back();
            //     dq.pop_back();
            //     dq.emplace_back(x * 10 + stoi(tmp));
            //     ++i;
            // }
        }
        else if (s.at(1) == '-')
        {
            // multiply  -1 to first deque value
            minus_available = true;
        }
        else if ((i != s.size() - 1) && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') && (s[i + 1] == '-'))
        {
            if (s[i] == '+')
            {
                b = dq.back();
                dq.pop_back();
                a = dq.back();
                dq.pop_back();
                dq.emplace_back((b + a) * -1);
            }
            else if (s[i] == '-')
            {
                b = dq.back();
                dq.pop_back();
                a = dq.back();
                dq.pop_back();
                dq.emplace_back(a + b);
            }
            else if (s[i] == '*')
            {
                b = dq.back();
                dq.pop_back();
                a = dq.back();
                dq.pop_back();
                dq.emplace_back((a * b) * -1);
            }
            else if (s[i] == '-')
            {
                b = dq.back();
                dq.pop_back();
                a = dq.back();
                dq.pop_back();
                dq.emplace_back((a / b) * -1);
            }
            s.pop_back(); // removing that extra '-' left at the back as it doesn't have two elements left in 'dq' to compare
        }
        else if ((s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') && (s[i + 1] != '-'))
        {
            if (s[i] == '+')
            {
                b = dq.back(); // 2nd element
                dq.pop_back();
                a = dq.back(); // 1st element
                dq.pop_back();
                dq.emplace_back(a + b);
            }
            else if (s[i] == '-')
            {
                b = dq.back(); // 2nd element
                dq.pop_back();
                a = dq.back(); // 1st element
                dq.pop_back();
                dq.emplace_back(a - b);
            }
            else if (s[i] == '*')
            {
                b = dq.back(); // 2nd element
                dq.pop_back();
                a = dq.back(); // 1st element
                dq.pop_back();
                dq.emplace_back(a * b);
            }
            else if (s[i] == '/')
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

int calculate(string s)
{

    deque<char> dq;
    string resultingString = "";
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            resultingString.push_back(s[i]);
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
                resultingString.push_back(dq.back());
                dq.pop_back();
            }
            dq.pop_back();
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            if (dq.back() == '*' || dq.back() == '/' || dq.back() == '+' || dq.back() == '-')
            {
                resultingString.push_back(dq.back());
                dq.pop_back();
                dq.emplace_back(s[i]);
            }
            else
            {
                dq.emplace_back(s[i]);
            }
        }
        else if (s[i] == '*' || s[i] == '/')
        {
            if (dq.back() == '/' || dq.back() == '*')
            {
                resultingString.push_back(dq.back());
                dq.pop_back();
                dq.emplace_back(s[i]);
            }
            else
            {
                dq.emplace_back(s[i]);
            }
        }
    }

    while (!dq.empty())
    {
        resultingString.push_back(dq.back());
        dq.pop_back();
    }

    // postfix to answer
    int answer = postfix_to_answer(resultingString);
    return answer; // the resulting string
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);
    int answer = calculate(str);
    cout << answer << endl;

    return 0;
}