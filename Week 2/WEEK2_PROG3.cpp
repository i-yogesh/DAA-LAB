#include <bits/stdc++.h>
using namespace std;

void solution(int *arr, int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) == k)
                count++;
        }
    }
    cout << count << endl;
}

int main()
{
    int t;
    cout << "Enter no of test cases" << endl;
    cin >> t;
    while (t--)
    {
        int arr[30];
        int n, key;
        cout << "Enter the size" << endl;
        cin >> n;
        cout << "Enter the elements" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "Enter the key k\n";
        cin >> key;
        solution(arr, n, key);
    }
    return 0;
}
