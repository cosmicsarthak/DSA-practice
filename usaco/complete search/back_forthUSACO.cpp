#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

vector<int> v1;
vector<int> v2;
set<int> ans;

void foo(int day, vector<int> &v1, vector<int> &v2, int s1_gallons, int s2_gallons)
{
    // base case
    if (day == 5) // 5th day doesn't exist
    {
        ans.emplace(s1_gallons);
        for (auto el : ans)
            cerr << el << " ";
        return;
    }

    // if (day % 2) // == 1
    // {
    for (int i = 0; i < v1.size(); i++)
    {
        int el = v1.at(i); // bucket
        vector<int> tmp1 = v1;
        vector<int> tmp2 = v2;
        tmp1.erase(tmp1.begin() + i);
        tmp2.emplace_back(el);
        // s1_gallons -= el;
        foo(day + 1, tmp2, tmp1, s2_gallons + el, s1_gallons - el);
        // foo(day + 1, v1, v2, s1_gallons);
        // don't know where `el` is in 'v2':
        // auto it = find(v2.begin(), v2.end(), el);
        // if (it != v2.end())
        // {
        //     v2.erase(it);
        // }
        // v1.emplace(v1.begin() + i, el);
        // // v1.emplace_back(el);
        // s1_gallons += el;
    }
    // }
    // else //  == 0
    // {
    //     for (int i = 0; i < v2.size(); i++)
    //     {
    //         int el = v1.at(i); // bucket
    //         vector<int> tmp1 = v1;
    //         vector<int> tmp2 = v2;
    //         tmp2.erase(tmp2.begin() + i);
    //         tmp1.emplace_back(el);
    //         // s1_gallons += el;
    //         foo(day + 1, tmp1, tmp2, s1_gallons + 1);
    //         // foo(day + 1, v1, v2, s1_gallons);
    //         // don't know where `el` is in 'v2':
    //         // auto it = find(v2.begin(), v2.end(), el);
    //         // if (it != v2.end())
    //         // {
    //         //     v2.erase(it);
    //         // }
    //         // v1.emplace(v1.begin() + i, el);
    //         // // v1.emplace_back(el);
    //         // s1_gallons += el;
    //     }
    // }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1;
    getline(cin, s1);
    string s2;
    getline(cin, s2);
    istringstream ss1(s1);
    istringstream ss2(s2);

    int tmp;
    while (ss1 >> tmp)
        v1.emplace_back(tmp);
    while (ss2 >> tmp)
        v2.emplace_back(tmp);

    int day = 1;
    int s1_gallons = 1000;
    int s2_gallons = 1000;

    foo(day, v1, v2, s1_gallons, s2_gallons);

    // for (auto el : ans)
    //     cerr << el << " ";

    cout << ans.size();

    return 0;
}