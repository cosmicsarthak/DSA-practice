/*
Given an array of positive numbers and a positive number ‘S’, find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0, if no such subarray exists.
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v = {2, 1, 5, 2, 3, 2};
    int k = 7, n = v.size();

    int window_start = 0, window_sum = 0, window_size = 0;
    int mn_size = 1e6, mn_start, mn_end;
    for (int window_end = 0; window_end < n; window_end++)
    {
        window_sum += v.at(window_end);
        ++window_size;

        while (window_sum >= k)
        {
            if (mn_size > window_size)
            {
                mn_size = window_size;
                mn_start = window_start;
                mn_end = window_end;
            }
            window_sum -= v.at(window_start);
            ++window_start;
            --window_size;
        }
    }

    cout << mn_size << endl;
    for (int i = mn_start; i <= mn_end; i++)
        cout << v.at(i) << " ";

    return 0;
}

/*
The time complexity of the above algorithm will be O(N)O(N).
The outer for loop runs for all elements and the inner while loop processes each element only once, therefore the time complexity of the algorithm will be O(N+N) which is asymptotically equivalent to O(N).
 */