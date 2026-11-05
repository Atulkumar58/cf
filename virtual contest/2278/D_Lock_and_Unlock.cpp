#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int& i: a) cin>>i;
        sort(a.begin(), a.end());

        int med= a[n/2];
        long long sum=0;
        int maxi=INT_MIN, mini=INT_MAX;
        for(int i=0; i<n; i++){
            sum+=abs(a[i]-med);
            maxi=max(maxi, a[i]);
            mini=min(mini, a[i]);
        }

        cout<<sum<<" "<<maxi-mini<<endl;
    }
}