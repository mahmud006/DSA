// iterative approach
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
//     int n = nums.size(), lis = 1;
//     vector<int> cache(n, 1);
//     for (int i = n - 2; i >= 0; i--)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (nums[i] < nums[j])
//             {
//                 cache[i] = max(cache[i], cache[j] + 1);
//                 lis = max(cache[i], lis);
//             }
//         }
//     }
//     cout << lis << endl;
// }

// recursive approach
#include <bits/stdc++.h>
using namespace std;
vector<int> cache;
int calculateLIS(int pos, vector<int> &nums)
{
    if (pos >= nums.size())
        return 0;
    if (cache[pos] != -1)
        return cache[pos];
    int lis = 1;
    for (int i = pos + 1; i < nums.size(); i++)
    {
        if (nums[pos] < nums[i])
        {
            lis = max(lis, 1 + calculateLIS(i, nums));
        }
    }
    return cache[pos] = lis;
}
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = nums.size(), lis = 1;
    cache.clear();
    cache.resize(n, -1);
    for (int i = 0; i < n; i++)
    {
        lis = max(lis, calculateLIS(i, nums));
        cout << calculateLIS(i, nums) << " ";
    }
    cout << lis << endl;
}