#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int&i: arr) cin>>i;

        int i= k-1, j= n-k;
        long long ans=0;
        while(i<n && j>=0){
            if(arr[i] > arr[j]){
                ans+= arr[i];
                arr[i]=0;
            }
            else{
                ans+= arr[j];
                arr[j]=0;
            }
            i++,j--;
        }
        cout<<ans<<endl;
    }
return 0;
}   