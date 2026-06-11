#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int& i: a) cin>>i;

        unordered_map<int, int> m;
        m[a[0]]=1;
        for(int i=1; i<n; i++){
            if(a[i] != a[i-1]){
                m[i]++;
            }
        }
        
    }
    return 0;
}