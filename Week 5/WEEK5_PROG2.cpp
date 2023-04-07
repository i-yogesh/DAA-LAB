#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int mainArrIndex = s;
    for (int i = 0; i < len1; i++)
        arr1[i] = arr[mainArrIndex++];
    mainArrIndex = mid + 1;
    for (int i = 0; i < len2; i++)
        arr2[i] = arr[mainArrIndex++];

    int index1 = 0, index2 = 0;
    mainArrIndex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (arr1[index1] < arr2[index2])
            arr[mainArrIndex++] = arr1[index1++];
        else
            arr[mainArrIndex++] = arr2[index2++];
    }
    while (index1 < len1)
        arr[mainArrIndex++] = arr1[index1++];
    while (index2 < len2)
        arr[mainArrIndex++] = arr2[index2++];
}
void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

void isPair(int *arr, int n, int target)
{
    mergeSort(arr, 0, n - 1);
    int i = 0, j = n - 1;
    while (i < j)
    {
        int curr = arr[i] + arr[j];
        if (curr == target)
        {
            cout << arr[i] << " " << arr[j] << endl;
            return;
        }
        if (curr < target)
            i++;
        else
            j--;
    }
    cout << "No Such Element Exist\n";
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
        int arr[50];
        cout << "Enter the elements\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int target;
        cout << "Enter the target\n";
        cin >> target;
        isPair(arr, n, target);
    }
    return 0;
}