#include <bits/stdc++.h>
using namespace std;

void insertionSort(int *arr, int n)
{
    int shifts = 0, comparisons = 0;
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current)
        {
            arr[j + 1] = arr[j];
            j--;
            comparisons++; // swaps
        }
        arr[j + 1] = current;
        shifts++;
    }
    shifts = shifts+comparisons;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Shifts: " << shifts << endl;
}

int main()
{
    int t;
    cout<<"Enter no of testcases\n";
    cin>>t;
    while(t--)
    {
        int arr[30];
        int n;
        cout << "Enter the size of the array\n";
        cin >> n;
        cout << "Enter the elements\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        insertionSort(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
    }
    return 0;
}