#include <bits/stdc++.h>
using namespace std;

const int MAX_gm = 5; // up to 20 garments at most and 20 models/garment
const int MAX_M = 6;  // maximum budget is 200
vector<vector<int>> price(MAX_gm, vector<int>(MAX_gm));

vector<vector<int>> memo(MAX_gm, vector<int>(MAX_M, 5));

void p(vector<vector<int>> v)
{
    for (auto el : v)
    {
        for (auto e : el)
            cout << e << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    p(memo);

    // ✅ use memset for single int values

    // resize
    cout << "✅used clear() + resize()" << endl;
    memo.clear();
    memo.resize(MAX_gm, vector<int>(MAX_M, -2));
    p(memo);

    // fill
    cout << "✅used resize()" << endl;
    memo.assign(MAX_gm, vector<int>(MAX_M, 0));
    p(memo);

    // fill
    cout << "✅used fill()" << endl;
    fill(memo.begin(), memo.end(), vector<int>(MAX_M, 1));
    p(memo);
}