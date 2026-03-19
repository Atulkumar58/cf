#include <iostream>
using namespace std;
bool setbit(int t){
    int count=0;
    while(t){
        if(t&1) count++;
        t>>=1;
    }
    if(count==1) return true;
    return false;
}
bool check(int x, int y){
    if(x%y ==0){
        int t= x/y;
        if(setbit(t)) return true;
    }else if(y%x==0){
        int t= y/x;
        if(setbit(t)) return true;
    }
    
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1];
        bool flag=1;
        for(int i=1; i<=n; i++){
            cin>>arr[i];
            if(!check(arr[i], i)){
                flag= 0;
            }
        }
        
        // arr[0]=0;
        // for(int i=1; i<=n; i++){
        //     if(2*i <=n && arr[i] > arr[2*i]) swap(arr[i], arr[2*i]);

        //     if(arr[i]== arr[i-1]+1) continue;
        //     else {
        //         flag=0;
        //         break;
        //     }
        // }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}