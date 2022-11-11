#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

vector<vector<char>> subsets;

void print()
{
    cerr << "  ...all subsets: { ";
    for (auto &el : subsets)
    {
        cerr << "(";
        for (auto &el2 : el)
        {
            cerr << el2 << ",";
        }
        cerr << ")  ";
    }
    cerr << "}\n";
}

void subprint(vector<char> &subset)
{
    cerr << "(";
    for (auto el : subset)
    {
        cerr << el << ",";
    }
    cerr << ")";
}

void generate(vector<char> &subset, vector<char> &nums, int k)
{
    cerr << "k=" << k << ": curSubset:";
    if (subset.empty())
    {
        cerr << "( )";
    }
    else
    {
        subprint(subset);
    }

    if (k == nums.size())
    {
        subsets.emplace_back(subset);
        cerr << " ⏩ adding currSubset: ";
        subprint(subset);
        cerr << " ⏩  making:";
        print();
        return;
    }

    cerr << "\n..generating at '" << k + 1 << "' for k=" << k << "...\n";
    cerr << "\n↪️ after previous generate() at k=" << k + 1 << ",   k gets back to '" << k << "' __.\n";
    generate(subset, nums, k + 1);

    cerr << "➕⊕ adding element '" << nums.at(k) << "' now curSubset: ";
    subset.emplace_back(nums.at(k));
    subprint(subset);
    cerr << "\n..generating at '" << k + 1 << "' for k=" << k << "...\n";
    generate(subset, nums, k + 1);

    subset.pop_back();
    cerr << "❌__removed element: '" << nums.at(k) << "' at k=" << k << endl
         << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<char> nums(n);
    for (auto &el : nums)
    {
        cin >> el;
    }
    vector<char> subset;

    generate(subset, nums, 0);

    cout << "  ...subsets: {";
    for (auto &el : subsets)
    {
        for (auto &el2 : el)
        {
            cout << el2 << ",";
        }
        cout << endl;
    }
    cout << "}\n";

    return 0;
}