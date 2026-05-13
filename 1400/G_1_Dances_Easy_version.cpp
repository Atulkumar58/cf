#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> a(n), b(n);
        a[0]= 1;
        for(int i=1; i<n; i++){
            cin>>a[i];
        }
        for(int & i: b) cin>>i;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i=0, j=0;
        int diff=0;
        while(i<n && j<n){
            if(a[i] < b[j]){
                i++, j++;
            }
            else{
                j++;
                diff= j-i;
            }
        }
        cout<<diff<<endl;
    }
    return 0;
}