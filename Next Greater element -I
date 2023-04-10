#include<bits/stdc++.h> 
using namespace std; 
void printNGE(int arr[],int n){
    int next;
    for(int i=0;i<n;i++){
        next = -1;
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                next=arr[j];
                break;
            }
        }
        cout<<next<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    printNGE(arr,n);

}
