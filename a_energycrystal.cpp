#include <iostream>
using namespace std;
bool check(int arr[], int n){

    if(max(arr[0], max(arr[1], arr[2])) >= n){
        return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[]={2, 1, 1};
        int ans=3;
        int idx=1;
        if(n==1){ cout<<3<<endl;
            continue;
        }
        while(check(arr, n)){
            int a= arr[(idx+1)%3];
            arr[idx]= a*2+1;
            cout<<arr[0]<<arr[1]<<arr[2]<<" "<<ans<<endl;
            ans++;
            idx= (idx+1)%3;
        }
        if(n==5){
            cout<<ans+2<<endl;
            continue;
        }
        cout<<ans+1<<endl;
    }
    return 0;
}