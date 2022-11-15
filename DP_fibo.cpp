#include <bits/stdc++.h>
using namespace std;
// vector<int> cache(1000, -1);
vector<int> cache(1000, 0);
int fib(int n)
{
    if (n <= 1)
        return n;
    if (cache[n] != -1)
        return cache[n];
    cache[n] = fib(n - 1) + fib(n - 2);
    return cache[n];
}
int main()
{
    // cout << fib(45) << endl;

    // iterative approach
    cache[1] = 1;
    for (int i = 2; i <= 50; i++)
    {
        cache[i] = cache[i - 1] + cache[i - 2];
    }
    for (int i = 1; i <= 20; i++)
    {
        cout << cache[i - 1] << endl;
    }
}