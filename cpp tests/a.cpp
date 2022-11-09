#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

struct Rect
{
    int x1, y1, x2, y2;
    // Rect(int x1, int y1, int x2, int y2) : x1{x1}, y1{y1}, x2{x2}, y2{y2} {}
};

int area(Rect rect)
{

    // cerr << (rect.x2 - rect.x1) << " -  " << (rect.y2 - rect.y1) << endl;

    int ans = ((rect.x2 - rect.x1) * (rect.y2 - rect.y1));
    return ans;
}

int inter(Rect p, Rect q)
{

    int xOverlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
    int yOverlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
    return xOverlap * yOverlap;

    // return ar;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("billboard.in", "r", stdin);
    // freopen("billboard.out", "w", stdout);

    int ans;
    Rect b1, b2, t;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;

    int ar = inter(b1, t);
    int ar2 = inter(b2, t);

    ans = area(b1) + area(b2) - ar - ar2;
    cout << ans;

    return 0;
}