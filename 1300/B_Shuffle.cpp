#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x, m;
        cin>>n>>x>>m;
        vector<int> interval ={x, x};
        for(int i=0; i<m; i++){
            int l, r;
            cin>>l>>r;
            if(r<interval[0] || l>interval[1]) continue;
            interval[0] = min(interval[0], l);
            interval[1] = max(interval[1], r);
        }

        cout<<interval[1]-interval[0]+1<<endl;
    }
    return 0;
}