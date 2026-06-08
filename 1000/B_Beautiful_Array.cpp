#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, k,b,s;
        cin>>n>>k>>b>>s;

        long long a= k*b;
        long long left= s-a;
        if(left < 0 || left > (k-1)*n){
            cout<<-1<<endl;
        }
        else{
            long long arr[n];
            for(int i=0; i<n; i++){
                arr[i]=0;
            }
            arr[0]=a;
            for(int i=0; i<n && left > 0; i++){
                long long add= min(left, k-1);
                arr[i]+=add;
                left-=add;
            }
            for(int i=0; i<n; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}