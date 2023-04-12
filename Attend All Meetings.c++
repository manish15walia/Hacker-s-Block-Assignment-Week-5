#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> meetings(n);

    for(int i=0; i<n; i++) {
        int start, end;
        cin >> start >> end;
        meetings[i] = {start, end};
    }

    sort(meetings.begin(), meetings.end());

    for(int i=0; i<n-1; i++) {
        if(meetings[i].second > meetings[i+1].first) {
            cout << "false" << endl;
            return 0;
        }
    }

    cout << "true" << endl;
    return 0;
}
