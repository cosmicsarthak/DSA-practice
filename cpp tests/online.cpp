#include <bits/stdc++.h>
using namespace std;

int sumAll(int n)
{
    // base case
    if (n <= 1)
    {
        return n;
    }
    // recursive case
    else
    {
        return (n + sumAll(n - 1));
    }
}
int main()
{

    vector<int> setName = {55, 900, 99, 2, 3, 4};

    // auto search = setName.find(2);
    // auto search = find(setName.begin(), setName.end(), 2);
    auto search = find(begin(setName), end(setName), 2);
    if (search != setName.end())
    {
        cout << "Found and element is... " << (search - setName.begin()) << '\n';
    }
    else
    {
        cout << "Not found\n";
    }

    cout << endl;

    set<int> st = {4566, 565465, 56, 557567, 342, 56756};

    for (auto el : st)
    {
        cout << el << " ";
    }
    cout << endl;

    // auto lb = lower_bound(st.begin(), st.end(), 56) - st.begin();
    // cout << (lb - st.begin());
    auto lb = st.lower_bound(342);
    cout << "____" << (*lb) << endl
         << endl;
    auto ub = st.upper_bound(342);
    cout << "____" << (*ub) << endl
         << endl;

    // return (std::lower_bound(v.begin(), v.end(), key) - v.begin());

    // unordered_set<int> ut = {4566, 565465, 56, 557567, 342, 56756};

    // for (auto el : st)
    // {
    //     cout << el << " ";
    // }
}