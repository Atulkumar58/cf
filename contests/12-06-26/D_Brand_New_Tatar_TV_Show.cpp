#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> a(n);
        unordered_map<int, int> m;
        for(int& i: a) {cin>>i; m[i]++;}

        sort(a.begin(), a.end());
        bool possible = false;
        for(int i= n-1; i>0; i--){
            if(a[i] != a[i-1]){
                if(m[a[i]] % 2 == 0){
                    possible = true;
                    break;
                }
                else if(a[i] - a[i-1] <= k){
                    possible = true;
                    break;
                }
            }
        }
        if(m[a[0]] % 2 == 0) possible = true;
        if(possible) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}