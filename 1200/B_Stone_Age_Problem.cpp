#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, q;
    cin>>n>>q;
    vector<int> a(n);
    vector<int> timestamp(n, 0);
    long long sum=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }
    int k, time=INT_MIN;
    int t=1;
    while(t<=q){
        int x;
        cin>>x;
        if(x==1){
            int i, v;
            cin>>i>>v;
            int oldval= a[i-1];
            if(time > timestamp[i-1]){
                oldval =  k;
            }
            
            sum = sum - oldval + v;
            a[i-1]=v;
            timestamp[i-1]=t;
            cout<<sum<<"\n";
        }
        else{
            cin>>k;
            time = t;
            sum= (long long)n*k;
            cout<<n*k<<"\n";

        }
        t++;
    }


    return 0;
}