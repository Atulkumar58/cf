#include <iostream>
using namespace std;

bool checkz(int* arr, int n){
    while(--n>=0){
        if(arr[n] != 0) return false;
    }
    return 1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int& i:arr) cin>>i;

        
        if(n&1){
            int count=0;
            int a[]= {0,1,1,n-1};
            int i;
            for(i=0; i<4; i++){
                if(checkz(arr, n)) break;

                int l= (i&1)? a[i-1]: a[i] , r= (i&1)? a[i]: a[i+1];
                int x=0;
                while(l<=r){
                    x^= arr[l];
                    l++;
                }
                l= (i&1)? a[i-1]: a[i] ;
                while(l<=r) arr[l++]=x;
                count++;
                
            }
            cout<<count<<endl;
            for(int i=0; i< count; i++){
                cout<<((i&1)? a[i-1]: a[i])+1 << " "<< ((i&1)? a[i]: a[i+1])+1<<endl;
            }
        }
        else{
            int count=0;
            while(!checkz(arr, n)){
                int x=0;
                for(int k: arr) x^=k;
                for(int& k: arr) k=x;
                count++;
                // for(int k: arr) cout<<k<<" ";
                // cout<<endl;
            } 
            cout<<count<<endl;
            while(count--){
                cout<<1<<" "<< n<<endl;
            }
        }
    }
    return 0;
}   