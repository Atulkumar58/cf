#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;

        vector<int> a(n);
        int maxi=0;
        for(int& i: a){ cin>>i; maxi= max(maxi, i);}
        
        int i=maxi, j=maxi+n;
        while(i<=j){
            int mid= i+(j-i)/2;

            bool possible= 0;
            for(int i=0; i<n; i++){
                int sum=0;
                for(int j=i; j<n && sum <= k; j++){
                    if(a[j] >= mid+i-j){
                        possible= 1;
                        break;
                    }
                    sum += mid+i-j - a[j];
                }
            }
            // cout<<mid<<" "<<possible<<"\n";
            if(possible) i= mid+1;
            else j= mid-1;
        }
        cout<<j<<"\n";
    }
    
    return 0;
}