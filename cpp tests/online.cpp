#include <iostream>
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

    int input = -6;
    // printing the answer
    cout << "The sum of first " << input << " numbers is " << sumAll(input);
    return 0;
}