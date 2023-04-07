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
        mergeSort(arr, 0, n - 1);

        int f = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                f = 1;
                cout << "Yes" << endl;
                break;
            }
        }
        if (f == 0)
            cout << "No" << endl;
    }
    return 0;
}