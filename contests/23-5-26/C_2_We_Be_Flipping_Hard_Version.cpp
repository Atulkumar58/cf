#include <iostream>
#include <vector>
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

        
        // pre compute
        int safe = -1;
        long long add = 0;
        for(int i=0; i<n; i++){
            add += a[i];
        }
        long long left=0;
        long long maxi = add;
        for(int i=0; i<n; i++){
            add -= a[i];
            if(maxi < add+left-a[i] && a[i] >0){
                maxi = add+left-a[i];
                safe = i;
            }
            left += abs(a[i]);
        }

        if(safe==-1 || safe<=0){
            cout<<0<<endl;
            cout<<endl;
            continue;
        }

        int sum=0;
        vector<int> idx;
        bool flag=1;
        int i=safe-1;
        for(; i>=0; i--){
            if(flag && a[i]>0){
                flag = 0;
                sum++;
                idx.push_back(i+1);
            }
            else if(!flag && a[i]<0){
                flag = 1;
                sum++;
                idx.push_back(i+1);
            }
        }

        cout<<sum+1<<endl;
        for(int i: idx) cout<<i<<" ";
        cout<<safe+1<<" "; cout<<endl;

    }
    return 0;
}