class Solution
{
public:
    int postfix_to_answer(string s)
    {
        deque<int> dq;
        int res = 0;
        int x;
        string tmp;
        int a, b;
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
                bool minus_available = true;
            }
            else if ((i != s.size() - 1) && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') && (s[i + 1] == '-'))
            {
                if (s[i] == '+')
                {
                    b = dq.back();
                    dq.pop_back();
                    a = dq.back();
                    dq.pop_back();
                    dq.emplace_back(b - a);
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
};