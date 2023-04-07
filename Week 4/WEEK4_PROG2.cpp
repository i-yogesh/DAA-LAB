#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int first, int last)
{
    int pivot = arr[last];

    int i = first - 1;
    int j = first;

    for (; j < last; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[last]);
    return i + 1;
}

int randomPartition(int *arr, int first, int last)
{
    srand(time(NULL));
    int random = first + rand() % (last - first);
    swap(arr[random], arr[last]);
    return partition(arr, first, last);
}
void QuickSort(int *arr, int first, int last)
{
    if (first >= last)
        return;
    int pivot = randomPartition(arr, first, last);
    QuickSort(arr, first, pivot - 1);
    QuickSort(arr, pivot + 1, last);
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
        // int comparisons = 0, swaps = 0;
        QuickSort(arr, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        // cout << "Comparisons: " << comparisons << endl;
        // cout << "Swaps: " << swaps << endl;
    }
    return 0;
}