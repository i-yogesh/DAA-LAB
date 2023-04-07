#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e, int &comparisons, int &inversions)
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
        comparisons++;
        if (arr1[index1] < arr2[index2])
            arr[mainArrIndex++] = arr1[index1++];
        else
        {
            inversions += len1 - index1;
            arr[mainArrIndex++] = arr2[index2++];
        }
    }
    while (index1 < len1)
        arr[mainArrIndex++] = arr1[index1++];
    while (index2 < len2)
        arr[mainArrIndex++] = arr2[index2++];
}
void mergeSort(int *arr, int s, int e, int &comparisons, int &inversions)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid, comparisons, inversions);
    mergeSort(arr, mid + 1, e, comparisons, inversions);
    merge(arr, s, e, comparisons, inversions);
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
        int comparisons = 0, inversions = 0;
        mergeSort(arr, 0, n - 1, comparisons, inversions);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        cout << "Comparisons: " << comparisons << endl;
        cout << "Inversions: " << inversions << endl;
    }
    return 0;
}