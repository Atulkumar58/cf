#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int s=1, e=n;
        int i=0, j=n-1;
        // vector<bool> visited(n+1, false)
        while(i < j){
            if(arr[i] == s){
                // visited[s]=1;
                s++;
                i++;
            }
            else if(arr[i] == e){
                // visited[e]=1;
                e--;
                i++;
            }
            else if(arr[j] == s){
                // visited[s]=1;
                s++;
                j--;
            }
            else if(arr[j] == e){
                // visited[e]=1;
                e--;
                j--;
            }
            else{
                break;
            }
        }
        if(i==j){
            cout<<-1<<endl;
        }else{
            cout<<i+1<<" "<<j+1<<endl;
        }
    }
    return 0;
}