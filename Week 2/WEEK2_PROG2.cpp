#include <bits/stdc++.h>
using namespace std;

void solution(int *arr, int n)
{
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] == arr[k])
                {
                    f = 1;
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                }
            }
        }
    }
    if (f == 0)
        cout << "No Sequence Found" << endl;
}

int main()
{
    int t;
    cout << "Enter no of test cases" << endl;
    cin >> t;
    while (t--)
    {
        int arr[30];
        int n;
        cout << "Enter the size" << endl;
        cin >> n;
        cout << "Enter the elements" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solution(arr, n);
    }
    return 0;
}
