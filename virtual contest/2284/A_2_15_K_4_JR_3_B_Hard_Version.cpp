#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <algorithm>


using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> a(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            // int x; cin>>x;
            // a[i]= 1<<x;
            cin>>a[i];
            sum+= (1<<a[i]);
        }
        
        sort(a.begin(), a.end(), greater<>());
        int diff= 0;
        for(int i: a){
            if(diff > 0){
                diff-= (1<<i);
            }
            else{
                diff+= (1<<i);
            }
        }
        int small= (sum-diff)/2;
        int l= small+diff;
        // cout<<diff<<" ";
        cout<< (long long)l*small <<endl;
        // unordered_set<long long> s;
        // s.insert(0);
        // for(int i: a){
        //     unordered_set<long long> next;
        //     for(auto j: s){
        //         next.insert(i + j);
        //         next.insert(abs((j-i)));
        //     }
        //     s = next;
        // }
        
        // long long mini= LLONG_MAX;
        // for(auto j: s){
        //     mini= min(mini, (long long)j);
        // }
        // // cout<< mini <<" "<< sum<<" ";
        // long long small= (sum-mini)/2;
        // long long l= small+mini;
        // cout<< l*small <<endl;

    }
}