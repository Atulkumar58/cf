#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int& i: arr){
            cin>>i;
        }
        
        int count=0;
        int j= n-1;
        while(j>= 0){
            while(j>=0 && arr[j] == arr[n-1]) j--;

            if(j>=0){
                int e= n-j-1;
                count++;
                j= j-e;
            }

        }
        cout<<count<<endl;
    }
    return 0;
}