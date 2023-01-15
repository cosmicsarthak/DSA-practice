#include <bits/stdc++.h>
using namespace std;

void p(vector<string> vs, int index)
{
    cerr << index << ":";
    for (auto el : vs)
        cerr << el << ".";
}

void addPalindromePartitions(int index, string &s, vector<string> &substrings, vector<vector<string>> &allSubstrings)
{
    if (index == s.size())
    {
        allSubstrings.push_back(substrings);
    }
    for (int i = index; i < s.size(); ++i) // ⚠️ for starts from the `index` as [we want the substring to continue after the previous substring]
    {
        p(substrings, index);
        cerr << "  "; // just debugging

        substrings.push_back(s.substr(index, i - index + 1));

        p(substrings, index);
        cerr << "+   "; // just debugging

        addPalindromePartitions(i + 1, s, substrings, allSubstrings); // ↷↷ calling recursion with the `updated` substrings
        substrings.pop_back();                                        // backtracking , Also, when one index is finished, the previous index will start from this Line ..
                                                                      // E.g.: when 3 is over, 2 will start from this line and thus another element will be removed from the substrings

        p(substrings, index);
        cerr << "-" << endl; // just debugging
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> allSubstrings;
    if (s.empty())
        return allSubstrings;

    vector<string> substrings;
    addPalindromePartitions(0, s, substrings, allSubstrings);

    return allSubstrings;
}

int main()
{
    string s;
    cin >> s;

    vector<vector<string>> result = partition(s);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
}