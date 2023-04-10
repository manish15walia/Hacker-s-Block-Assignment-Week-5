// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

void printNGE(int A[], int n)
{
	int arr[2 * n];
	for (int i = 0; i < 2 * n; i++)
		arr[i] = A[i % n];
	int next, i, j;
	for (i = 0; i < n; i++) {
		next = -1;
		for (j = i + 1; j < 2 * n; j++) {
			if (arr[i] < arr[j]) {
				next = arr[j];
				break;
			}
		}
		cout << next << " ";
	}
}

// Driver Code
int main()
{
	int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
	
	printNGE(arr, n);
	return 0;
}

