#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2==0 || n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n==3){
            cout<<1<< " "<<3<<" "<<2<<endl;
            continue;
        }
        int arr[n];
        int a=1;
        int i;
        for( i=0;i<=n/2;i++){

           arr[(i+a)%n]=i+1;
           a+=2;
        }
        a=2;
        for(; i<n; i++){
            arr[(i+a)%n]=i+1;
           a+=2;
        }
        for(i=0; i<n; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}