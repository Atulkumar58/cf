#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int count=0;
        for(int i=0; i<n-1; i++){
            if((abs(arr[i]-6)== abs(1-arr[i+1]) ) || (arr[i]== arr[i+1])){
                count++;
                i++;
            }
            // cout<<abs(arr[i]-6)<<" "<<abs(1-arr[i+1])<<endl;
            // cout<<count<<" ";
        }
        cout<<count<<endl;
    }
    return 0;
}