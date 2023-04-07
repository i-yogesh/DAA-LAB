#include <bits/stdc++.h>
using namespace std;

void countSort(int *arr, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, arr[i]);

    int freq[maxi + 1];
    // initializing freq array
    for (int i = 0; i <= maxi; i++)
        freq[i] = 0;

    // count of each element in array
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    // Cumulative frequency
    for (int i = 1; i <= maxi; i++)
    {
        freq[i] = freq[i] + freq[i - 1];
    }
    // right position
    int *ans = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        ans[--freq[arr[i]]] = arr[i];
    }
    // copy ans to og array
    for (int i = 0; i < n; i++)
        arr[i] = ans[i];
}

void common(int *arr1, int m, int *arr2, int n)
{
    countSort(arr1, m);
    countSort(arr2, n);
    vector<int> ans;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}
int main()
{
    int n, n2;
    cout << "Enter the size of the first array\n";
    cin >> n;
    int arr[50];
    cout << "Enter the elements\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the size of the second array\n";
    cin >> n2;
    int arr2[50];
    cout << "Enter the elements\n";
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];
    common(arr, n, arr2, n2);
    return 0;
}