#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, k1, k2;
    cin>>n>>k1>>k2;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }for(int i=0; i<n; i++){
        cin>>b[i];
    }

    int x= k1+k2;
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        pq.push(abs(a[i]-b[i]));
    }
    while(x--){
        int t= pq.top();
        pq.pop();
        if(t>0) pq.push(t-1);
        else pq.push(t+1);
    }

    long long ans=0;
    while(!pq.empty()){ ans+= (long long)pq.top()*pq.top(); pq.pop(); }
    cout<<ans<<endl;

    return 0;
}