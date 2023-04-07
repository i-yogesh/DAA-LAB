#include <bits/stdc++.h>
using namespace std;

void selectionSort(int *arr, int n)
{
    int noOfSwaps = 0, noOfComparisons = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            noOfComparisons++;
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        noOfSwaps++;
        swap(arr[i], arr[minIdx]);
    }
    cout << "No of swaps: " << noOfSwaps << endl;
    cout << "No of comparisons: " << noOfComparisons << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int arr[30];
        int n;
        cout << "Enter the size of the array\n";
        cin >> n;
        cout << "Enter the elements\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        selectionSort(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    return 0;
}