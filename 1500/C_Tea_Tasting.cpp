#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
vector<long long> pre;
int binary_search(long long val){
    int l=0;
    int r= pre.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(pre[mid] == val) return mid;
        else if(pre[mid]>val) r= mid-1;
        else l= mid+1;
    }
    return l;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        // vector<long long> pre(n);
        pre.resize(n);
        for(int& i: a) cin>>i;
        for(int i=0; i<n; i++){
            cin>>b[i];
            if(i==0) pre[i] = b[i];
            else pre[i] = pre[i-1] + b[i];
        }
        pre.push_back(LONG_LONG_MAX);

        vector<long long> sweepline(n+1, 0);
        // for(auto i: sweepline) cout<<i<<" ";
        // cout<<endl;
        vector<long long> sum(n+1, 0);
        for(int i=0; i<n; i++){
            long long p= (i==0) ? 0 : pre[i-1];
            int idx= binary_search(a[i]+p);
            // cout<<idx<<" ";
            sweepline[i] += 1;
            sweepline[idx] -= 1;
            long long temp= a[i]+p - ((idx == 0) ? 0 : pre[idx-1]);
            // cout<<temp<<endl;
             sum[idx] += temp;
            // cout<<sum[idx]<<endl;
        }

        vector<long long> ans;
        long long total_sum=0;
        for(int i=0; i<n; i++){
            total_sum+= sweepline[i];
            // cout<<total_sum<<" "<<sum[i]<<endl;
            cout<<total_sum*b[i] + sum[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}