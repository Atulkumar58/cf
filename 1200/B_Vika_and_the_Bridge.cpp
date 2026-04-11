#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int i=0, j= n-1;

        while(i<=j){
            int mid= (i+j)/2;

            vector<int> allow(k+1, mid); //allowed till index 
            vector<bool> canrepaint(k+1, true); //can repaint till index 
            canrepaint[0]= false;
            allow[0] = -1;
            bool cancross= false;
            for(int idx=0; idx<n; idx++){
                if(allow[arr[idx]] >= idx){
                    allow[arr[idx]] = idx + mid+1;
                }
                else if(canrepaint[arr[idx]]){
                    if(idx - allow[arr[idx]]-1  <= mid){
                        canrepaint[arr[idx]]= false;
                        allow[arr[idx]] = idx + mid+1;
                    }
                }

                if(allow[arr[idx]] >= n){
                    cancross= true;
                    break;
                }
            }
            for(int idx=0; idx<allow.size(); idx++){
                if(n -allow[idx]-1  <= mid && canrepaint[idx]){
                    cancross= true;
                    break;
                }
            }
            // cout<<"mid: "<<mid<<" cancross: "<<cancross<<endl;
            if(cancross){
                j= mid-1;
            }
            else{
                i= mid+1;
            }
        
        }
        cout<<i<<endl;
        // cout<<"------------------"<<endl;
    }
    return 0;
}