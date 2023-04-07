#include <bits/stdc++.h>
using namespace std;

int firstPos(int *arr, int n, int target)
{
	int s = 0, e = n - 1, idx = -1;
	while (s <= e)
	{
		int mid = s + (e - s) / 2;
		if (arr[mid] == target)
		{
			idx = mid;
			e = mid - 1;
		}
		else if (target < arr[mid])
			e = mid - 1;
		else
			s = mid + 1;
	}
	return idx;
}

int lastPos(int *arr, int n, int target)
{
	int s = 0, e = n - 1, idx = -1;
	while (s <= e)
	{
		int mid = s + (e - s) / 2;
		if (arr[mid] == target)
		{
			idx = mid;
			s = mid + 1;
		}
		else if (target < arr[mid])
			e = mid - 1;
		else
			s = mid + 1;
	}
	return idx;
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

		int target;
		cout << "Enter the target\n";
		cin >> target;

		int f = firstPos(arr, n, target);
		int l = lastPos(arr, n, target);
		if (f == -1)
		{
			cout << "Key Not Present\n";
		}
		else
		{
			cout<<target<<" "<<(l - f + 1) << endl;
		}
	}

	return 0;
}
