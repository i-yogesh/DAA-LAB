#include <bits/stdc++.h>
using namespace std;

void linearSearch(int *arr, int n, int key)
{
    int c = 0, f = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            f = 1;
            cout << "Present " << c + 1 << endl;
            break;
        }
        c++;
    }
    if (f == 0)
        cout << "Not Present " << c << endl;
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
        linearSearch(arr, n, key);
    }
    return 0;
}