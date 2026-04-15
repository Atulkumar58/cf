#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a;
        cin>>a;
        string b;
        cin>>b;
        vector<int> diff;
        int s=0;
        for(char c: a){
            if(c=='1') s++;
            else s--;
            diff.push_back(s);
        }
        bool same= true;
        bool can = true;
        for(int i= n-1; i>=0; i--){
            if(same){
                if(a[i]!= b[i]){
                    if(diff[i] != 0){
                        can = false;
                        break;
                    }else{
                        same = false;
                    }
                }
                    
            }else{
                if(a[i] == b[i]){
                    if(diff[i] != 0){
                        can = false;
                        break;
                    }else{
                        same = true;
                    }
                }
            }
        }
        if(can) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}