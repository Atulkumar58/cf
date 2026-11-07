#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());

        vector<int> ans;
        for(int i=n-k;i<n;i++){
            ans.push_back(a[i]);
        }
        for(int i=n-k-1;i>=0;i--){
            ans.push_back(a[i]);
        }

        if(n!=k && a[n-1] == a[n-k-1]){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            for(int i: ans){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
}