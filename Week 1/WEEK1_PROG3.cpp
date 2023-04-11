#include <bits/stdc++.h>
using namespace std;

void jumpSearch(int arr[], int n, int k)
{
    int start = 0;
    int c = 1;
    int end = sqrt(n);
    while (arr[end] < k && end < n)
    {
        c++;
        start = end;
        end = end + sqrt(n);
        if (end > n - 1)
        {
            end = n - 1;
            break;
        }
    }
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == k)
        {
            cout << "present " << c;
            return;
        }
    }
    cout << "not present " << c;
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
