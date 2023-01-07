#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

vector<int> permutation;
vector<bool> chosen(4);
int n = 4;

void search()
{
    if (permutation.size() == n)
    {
        // process permutation
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cerr << "hell" << endl;
            if (chosen[i])
                continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (auto el : permutation)
    {
        cout << el << " ";
    }

    search();
}