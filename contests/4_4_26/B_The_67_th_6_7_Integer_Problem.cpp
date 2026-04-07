#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> a(7);
        for(int& i: a){
            cin>>i;
        }

        sort(a.begin(), a.end());
        int ans = 0;
        for(int i=0; i<7; i++){
            if(i == 6){
                ans+= a[i];
            }else{
                ans+= (-a[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}