#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

struct Node
{
    int val;    /* int is '4 bytes' */
    Node *next; // stores address of the 'next Node' : 'next' relative to the 'current Node with value "val" '
    /* here pointer is of type int* : 'int*' pinter is '4 bytes' */

    /* so, '1 Node' size on memory is (4+4 = 8 bytes) */
};

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
