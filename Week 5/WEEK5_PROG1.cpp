#include <bits/stdc++.h>
using namespace std;

// const int maxi = 26;
void countSort(vector<char> &arr)
{
    int maxi = *max_element(arr.begin(), arr.end());
    int freq[maxi + 1];
    // initializing freq array
    for (int i = 0; i <= maxi; i++)
        freq[i] = 0;

    // count of each element in array
    for (int i = 0; i < arr.size(); i++)
        freq[arr[i]]++;

    int maxO = -1, maxC = 0;
    for (int i = 0; i <= maxi; i++)
    {
        if (freq[i] > maxO)
        {
            maxO = freq[i];
            maxC = i;
        }
    }
    if (maxO == 1)
        cout << "No duplicates present\n";
    else
        cout << (char)maxC << " - " << maxO << endl;
}
int main()
{
    // vector<int> arr = {5, 2, 1, 3, 4};
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cout << "Enter the size of the array\n";
        cin >> n;
        vector<char> arr(n);
        cout << "Enter the elements\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        countSort(arr);
    }
    return 0;
}