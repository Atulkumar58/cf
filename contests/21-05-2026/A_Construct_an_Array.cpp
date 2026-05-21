#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i+=2){
            arr[i] = i+1;
        }
        for(int i=1; i<n; i+=2){
            arr[i] = n+1+i;
        }
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}