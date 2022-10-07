int countPrimes(int n)
{
    int count = 0;
    vector<bool> is_prime(n, true);
    if (n == 0)
        return 0;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < n; j += i)
                is_prime[j] = false;
        }
    }

    for (auto el : is_prime)
    {
        if (el == true)
        {
            ++count;
        }
    }

    return count;
}