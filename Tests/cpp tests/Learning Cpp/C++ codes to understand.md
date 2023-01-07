```cpp
unordered_map<int,int> unmap;
for(int i=0 ; i<nums.size() ; i++){
    unmap[nums[i]]++;
    if(unmap[nums[i]] >= 2) return true;
}
return false;
```

- https://stackoverflow.com/questions/39906504/how-to-count-duplicates-in-a-vector-c

```cpp
// C++ program to illustrate std::istringstream
// to tokenize the string
#include <iostream>
#include <sstream>
#include <string>
using std::istringstream;
using std::string;
using std::cout;

// Driver Code
int main()
{
	// Input string
	string str("abc, def, ghi");

	// Object class of istringstream
	istringstream my_stream(str);

	// To store the stream string
	string token;

	size_t pos = -1;

	// Traverse till stream is valid
	while (my_stream >> token) {

		// If ',' is found then tokenize
		// the string token
		while ((pos = token.rfind(','))
			!= std::string::npos) {
			token.erase(pos, 1);
		}

		// Print the tokenize string
		cout << token << '\n';
	}
}
```

---

<!-- <=======================> -->

CodeChef Starters 12

```cpp
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    ll ans;

    for (int i = 0; i < t; i++)
    {
        ll ans1 = 0,
           ans2 = 0;

        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        ll sub = abs(n - m);
        ans1 += sub * x;
        int mn = min(n, m) - 1;
        ans1 += mn * y;

        ans2 = ((n - 1) * x) + ((m - 1) * x);

        ll ans = min(ans1, ans2);

        cout << ans << endl;
    }

    return 0;
}

```

---

```cpp
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

void solve(int n)
{
    int ans = pow(10, n - 1);
    int x = pow(10, n);
    int a;
    for (; ans < x; ans++)
    {

        if (ans % 2 != 0)
        {
            if ((ans % 3 == 0) && (ans % 9 != 0) && (ans % 9 != 0))
            {
                // cout << ans << endl;
                // return;
                a = ans;
                break;
            }
        }
    }
    cout << a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int ans = pow(10, n - 1);
        int x = pow(10, n);
        int a;
        for (; ans < x; ans++)
        {

            if (ans % 2 != 0)
            {
                if ((ans % 3 == 0) && (ans % 9 != 0))
                {
                    // cout << ans << endl;
                    // return;
                    a = ans;
                    cout << a << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
```

---

```cpp
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    ll ans;

    for (int i = 0; i < t; i++)
    {
        ll ans1 = 0,
           ans2 = 0;

        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        ll sub = abs(n - m);
        ans1 += sub * x;
        int mn = min(n, m) - 1;
        ans1 += mn * y;

        ans2 = ((n - 1) * x) + ((m - 1) * x);

        ll ans = min(ans1, ans2);

        cout << ans << endl;
    }

    return 0;
}
```

# Bitwise Operarations

- https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/discuss/1798914/The-Fastest-C%2B%2B-Code-(Easy-to-Understand)
