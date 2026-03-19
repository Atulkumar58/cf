#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n; i++){
            cin>>arr[i];
        }
        int a[5]={3, 1, 2, 1, 1};
        for(int i=0; i<n; i++){
            switch(arr[i]){
                case 0: a[0]--;
                // cout<<0;
                break;
                case 1: a[1]--;
                // cout<<1;
                break;
                case 2 : a[2]--;
                // cout<<2;
                break;
                case 3: a[3]--;
                // cout<<3;
                break;
                case 5: a[4]--;
                break;
            }
            if(a[0]<=0 && a[1]<=0 && a[2]<=0 && a[3]<=0  && a[4]<=0){
                cout<<i+1<<endl;
                break;
            }
            if(i==n-1){

                cout<<0<<endl;
                // break;
            }
        }
    }
    return 0;
}