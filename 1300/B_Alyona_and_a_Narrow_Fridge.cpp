#include <iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, h;
    cin>>n>>h;
    vector<int> a;
    bool flag=false;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(flag) continue;
        a.push_back(x);
        int idx=a.size()-1;
        while(idx >0 && a[idx] < a[idx-1]){
            swap(a[idx], a[idx-1]);
            idx--;
        }

        int sum=0;
        idx= a.size()-1;
        while(idx >= 0 &&  sum <= h){
            sum += a[idx];
            idx-=2;
        }

        if(sum > h){
            flag=true;
            cout<<i<<endl;
        }
    }
    if(!flag){
        cout<<n<<endl;
    }

    return 0;
}