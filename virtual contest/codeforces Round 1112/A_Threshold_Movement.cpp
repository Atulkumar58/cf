#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int& i: a){
            cin>>i;
        }

        int maxi= INT_MIN;
        int mini= INT_MAX;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                mini= min(mini, a[i]);
            }
            else maxi= max(maxi, a[i]);
        }

        if(n%2==0 && mini > maxi+1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;

        }
    }
    return 0;
}