// TC: O(N*2^N)
#include <bits/stdc++.h>
using namespace std;
void gen_subsets(int curr, vector<int> &subset, vector<int> &arr)
{
    if (curr == arr.size())
    {
        for (auto it : subset)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // arr[curr] include
    subset.push_back(arr[curr]);
    gen_subsets(curr + 1, subset, arr);
    subset.pop_back();

    // arr[curr] exclude
    gen_subsets(curr + 1, subset, arr);
}
int main()
{
    vector<int> arr = {20, 30, 40};
    vector<int> subset;
    gen_subsets(0, subset, arr);
}