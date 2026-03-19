#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int arr[n];
        bool inc= true;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(i>0 && arr[i]<arr[i-1])inc=false;
        }
        if(k>1 || inc){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}