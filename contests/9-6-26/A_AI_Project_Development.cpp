#include <iostream>
#include <climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x, y,z;
        cin>>n>>x>>y>>z;

        int ans= (n-1)/(x+y) +1;
        //with ai
        int time=0;
        n= n- z*x;
        if(n > 0){
            time+= z;
            time+= ((n-1)/(x+ 10*y) +1);
        }
        else time=INT_MAX;
        // cout<<ans<<" "<<time<<" ";
        cout<<min(ans, time)<<endl;
    }
    return 0;
}