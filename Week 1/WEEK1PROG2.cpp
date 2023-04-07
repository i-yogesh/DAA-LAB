#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int n, int target)
{
	int s = 0, e = n - 1, idx = -1, c = 0;
	while (s <= e)
	{
		c++;
		int mid = s + (e - s) / 2;
		if (arr[mid] == target)
		{
			idx = mid;
			break;
		}
		else if (target < arr[mid])
			e = mid - 1;
		else
			s = mid + 1;
	}
	if (idx == -1)
	{
		cout << "Not Present " << c << endl;
	}
	else
		cout << "Present " << c << endl;
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
		binarySearch(arr, n, key);
	}
	return 0;
}
