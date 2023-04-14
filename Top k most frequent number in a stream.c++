#include <bits/stdc++.h>
using namespace std;

void kTop(int n,int k,int a[])
{
	vector<int> top(k + 1);

	unordered_map<int, int> freq;

	for (int m = 0; m < n; m++) {
		freq[a[m]]++;

		top[k] = a[m];

		auto it = find(top.begin(), top.end() - 1, a[m]);

		for (int i = distance(top.begin(), it) - 1; i >= 0; --i) {
		
			if (freq[top[i]] < freq[top[i + 1]])
				swap(top[i], top[i + 1]);

		
			else if ((freq[top[i]] == freq[top[i + 1]])
					&& (top[i] > top[i + 1]))
				swap(top[i], top[i + 1]);
			else
				break;
		}

		for (int i = 0; i < k && top[i] != 0; ++i)
			cout << top[i] << ' ';
	}
	cout << endl;
}

int main()
{
    int t;
    cin>>t;
    while(t-->0){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

	kTop(n, k,arr);
	return 0;
    }
}
