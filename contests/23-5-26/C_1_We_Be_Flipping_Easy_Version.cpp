#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int& i:a) cin>>i;

        int sum=0;
        vector<int> idx;
        bool flag=1;
        for(int i= n-1; i>=0; i--){
            if(flag && a[i] > 0) {
                flag=0;
                idx.push_back(i+1);
                sum++;
            }
            else if(!flag && a[i] <0){
                flag=1;
                idx.push_back(i+1);
                sum++;
            }
        }
        cout<<sum<<endl;
        for(int i: idx) cout<< i<<" "; cout<<endl;
    }
    return 0;
}