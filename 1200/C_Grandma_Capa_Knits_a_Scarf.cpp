#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int checker(string s, int i, int j, char c){
    int ans=0;
    while(i < j){
        if(s[i] != s[j]){
            if(s[i] == c) {ans++; i++;}
            else if(s[j] == c) {ans++; j--;}
            else return INT_MAX;
            continue;
        }
        i++;
        j--;

    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        int i=0, j=n-1;
        int ans=0;
        while(i < j){
            if(s[i] != s[j]){
                ans = checker(s, i, j, s[i]);
                ans = min(ans, checker(s, i, j, s[j]));
                break;
            }
            i++;
            j--;
        }
        if(ans == INT_MAX) ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}