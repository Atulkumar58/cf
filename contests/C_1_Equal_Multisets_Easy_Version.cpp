#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> pos(n+1);
        for(int i=0; i<n; i++) {
            cin>>a[i];
            pos[a[i]] = i;
        }
        for(int& i: b) cin>>i;

            bool flag = true;
            unordered_map<int,bool> mp;
            for(int i=0; i<n; i++){
                if(i >= k){
                    mp[b[i-k]] = false;
                }
                if(b[i] != -1 && mp[b[i]]) flag = false;
                if(b[i] != -1) mp[b[i]] = true;
               if(b[i] != -1 && b[i] != a[i]){
                    int l= n-k;
                    int r= k+1;
                    if(i>r || i<l || pos[b[i]]>r || pos[b[i]]<l) flag = false;
                    
               }
               
            }

            if(flag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        
    }
    return 0;
}