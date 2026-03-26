#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++){ cin>>a[i];}

        sort(a.begin(), a.end());
        long long sum=1;
        if(a[0] != 1){
            cout<<"NO"<<endl;
            continue;
        }
        bool flag = true;
        for(int i=1; i<n; i++){
            if((long long)a[i] > sum){
                // cout<<"No"<<endl;
                flag = false;
                break;
            }
            sum+= a[i];
            if(sum > 1e6){
                break;
            }
        }

        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}