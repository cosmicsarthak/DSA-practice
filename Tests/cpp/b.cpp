#include <bits/stdc++.h>

using namespace std;

void p(vector<string> vs, int index)
{
    cerr << index << ":";
    for (auto el : vs)
        cerr << el << ".";
}

bool isPalindrome(const string &s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

void addPalindromePartitions(int index, string &s, vector<string> &substrings, vector<vector<string>> &allSubstrings)
{
    if (index == s.size())
    {
        allSubstrings.push_back(substrings);
    }
    for (int i = index; i < s.size(); ++i) // ⚠️ for starts from the `index` as [we want the substring to continue after the previous substring]
    {
        string tmp = s.substr(index, i - index + 1);
        cerr << tmp;

        if (isPalindrome(s, index, i))
        {
            cerr << "..." << tmp;

            substrings.push_back(s.substr(index, i - index + 1)); // calling recursion with the updated substrings
            addPalindromePartitions(i + 1, s, substrings, allSubstrings);
            substrings.pop_back();
        }
        cerr << endl;
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> partition_substrings;
    if (s.empty())
        return partition_substrings;

    vector<string> substrings;
    addPalindromePartitions(0, s, substrings, partition_substrings);

    return partition_substrings;
}

int main()
{
    // string s;
    // cin >> s;
    string s = "aab";
    vector<vector<string>> result = partition(s);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
}
