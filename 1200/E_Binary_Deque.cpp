#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t; 
    while(t--){
        int n,s;
        cin>>n>>s;
        vector<int> a(n);
        for(int & i: a) cin>>i;

        int i=0, j=0;
        int sum=0;
        int l=0;
        while(j<n){
            if(sum <= s){
                l= max(l, j-i);
                sum+= a[j];
                j++;
            }
            else{
                sum-= a[i];
                i++;
            }
        }
        if(sum <= s){
                l= max(l, j-i);
        }
        if(sum < s) cout<<-1<<endl;
        else cout<<n-l<<endl;
        
    }
    return 0;
}