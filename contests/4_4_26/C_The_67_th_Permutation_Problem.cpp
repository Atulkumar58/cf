#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int i= 1, j= 3*n;
        for(int k=0; k<n; k++){
            cout<<i<<" ";i++;
            cout<<j<<" ";j--;
            cout<<j<<" ";j--;
        }
        cout<<endl; 
    }
    return 0;
}   