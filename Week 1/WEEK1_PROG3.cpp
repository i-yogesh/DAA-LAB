#include <bits/stdc++.h>
using namespace std;

void jumpSearch(int *arr, int n, int key)
{
    int step = sqrt(n);
    int prev = 0, comp = 0;
    while (arr[min(step, n) - 1] < key)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
        {
            cout << "Not Present " << comp << endl;
            return;
        }
        comp++;
    }
    while (arr[prev] < key)
    {
        prev++;
        if (prev == min(step, n))
        {
            cout << "Not Present " << comp << endl;
            return;
        }
        comp++;
    }
    if (arr[prev] == key)
    {
        cout << "Present " << comp << endl;
        return;
    }
    cout << "Not Present " << comp << endl;
}
int main()
{
    int t, n;
    cout << "Enter no of test cases" << endl;
    cin >> t;
    while (t--)
    {
        cout << "Enter no of elements" << endl;
        cin >> n;

        int arr[60];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int key;

        cout << "Enter the element to be searched" << endl;
        cin >> key;
        jumpSearch(arr, n, key);
    }
    return 0;
}