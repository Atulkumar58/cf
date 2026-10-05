#include <iostream>
#include <bits/stdc++.h>

using namespace std;
set<int> s;
int enc(int a, int b){
    return a*1000 + b;
}
int ss(int n){
    int sum=0;
    while(n){
        sum+= (n%10)*(n%10);
        n/=10;
    }
    return sum;
}
bool check(int a, int b){
    if(a==b) return true;
    if(s.find(enc(a,b))!=s.end()) return false;
    s.insert(enc(a,b));
    
    return check(ss(a), ss(b));
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j= i+1; j<n; j++){
                s.clear();
                if(check(ss(v[i]), ss(v[j]))){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
return 0;
}