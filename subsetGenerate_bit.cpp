// TC: O()
#include <bits/stdc++.h>
using namespace std;
bool checkBit(int n, int pos)
{
    return (n & (1 << pos)) > 0;
}
int main()
{
    vector<int> arr = {20, 30, 40};
    int n = arr.size();
    int nsubset = 1 << n;
    for (int i = 0; i < nsubset; i++)
    {
        vector<int> subset;
        for (int j = 0; j < arr.size(); j++)
        {
            if (checkBit(i, j))
                subset.push_back(arr[j]);
        }
        for (auto it : subset)
            cout << it << " ";
        cout << endl;
    }
}