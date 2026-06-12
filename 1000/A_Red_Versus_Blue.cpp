#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r, b;
        cin>>n>>r>>b;
        b++;
        // int x= 
        while(b){
            int t= (r-1)/b +1;
            while(t-- && r>0){
                r--;
                cout<<"R";
            }
            if(b!= 1) cout<<"B";
            b--;
        }
        // for(int i=0; i<= b; i++){
        //     for(int j=0; j<x && r; j++){
        //         r--;
        //         cout<<"R";
        //     }
        //     if(i!= b){
        //         cout<<"B";
        //     }
        // }
        cout<<endl;
    }
    return 0;
}