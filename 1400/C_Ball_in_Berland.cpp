#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, k;
        cin>>a>>b>>k;
        
        vector<int> boys(a+1, 0);
        vector<int> girls(b+1, 0);
        for(int i=0; i<k; i++){
            int x;cin>>x;
            boys[x]++;
        }
        for(int i=0; i<k; i++){
            int x; cin>>x;
            girls[x]++;
        }
        long long pairs=((long long)k*(k-1))/2;
        for(int i: boys){
            if(i>1){
                pairs-= ((long long)i * (i-1))/2;
            }
        }
        for(int i: girls){
            if(i > 1) pairs-= ((long long) i*(i-1))/2;
        }
        cout<<pairs<<endl;
    }
    return 0;
}