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
        for(int& i: arr) cin>>i;

        vector<int> a, b;
        a.push_back(arr[0]);
        int i=1;
        while(i<n && arr[i-1] >= arr[i]){
            a.push_back(arr[i]); i++;
        }
        if(i<n) b.push_back(arr[i++]);
        
        int ans=0;
        while(i<n){
            if(a.back() <= b.back()){
                if(arr[i] <= a.back()){
                    a.push_back(arr[i]);
                }else if(arr[i] <= b.back()){
                    b.push_back(arr[i]);
                }else{
                    a.push_back(arr[i]);
                    ans++;
                }
            }
            else{
                if(arr[i] <= b.back()){
                    b.push_back(arr[i]);
                }else if(arr[i] <= a.back()){
                    a.push_back(arr[i]);
                }else{
                    b.push_back(arr[i]);
                    ans++;
                }
            }
            i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}