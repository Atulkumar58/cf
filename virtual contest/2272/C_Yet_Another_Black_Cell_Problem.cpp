#include <bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        vector<int> a(n);
        int maxi= 0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(i > 0) maxi= max(maxi, a[i]-a[i-1]);
        }
        // cout<<maxi<<" ";
        int i=1, j= maxi;
        // cout<<maxi<<" ";
        while(i<=j){
            int mid= (i+j)/2;

            int cnt=0;
            int k=1;
            if(a[1]-a[0] > 2*mid) cnt++;
            else if(a[1]-a[0] > mid){ cnt++; k=2;}
            for(; k<n; k++){
                int x= a[k]-a[k-1];
                if(x <= mid) continue;
                else {
                    if(k<n-1){
                        if(a[k+1]-a[k] <= mid) k++;
                        else if(a[k+1]-a[k] <= 2*mid){
                            k++;
                            cnt++;
                        }
                        else{
                            cnt++;
                        }
                    }
                    else cnt++;
                }
            }

            if(cnt <= x){
                j= mid-1;
            }
            else{
                i= mid+1;
            }
        }
        cout<<i<<endl;
    }
}