#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr)
{
    int maxi = *max_element(arr.begin(), arr.end());
    int freq[maxi + 1];
    // initializing freq array
    for (int i = 0; i <= maxi; i++)
        freq[i] = 0;
        
    // count of each element in array
    for (int i = 0; i < arr.size(); i++)
        freq[arr[i]]++;

    // Cumulative frequency
    for (int i = 1; i <= maxi; i++)
    {
        freq[i] = freq[i] + freq[i - 1];
    }
    // right position
    vector<int> ans(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        ans[--freq[arr[i]]] = arr[i];
    }
    // copy ans to og array
    for (int i = 0; i < arr.size(); i++)
        arr[i] = ans[i];
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
        vector<int> arr(n);
        cout << "Enter the elements\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << "Enter k\n";
        cin >> k;

        countSort(arr);
        // cout<<"Kth largest "<<arr[n-k]<<endl;
        cout << "Kth Smallest " << arr[k - 1] << endl;
    }
    return 0;
}