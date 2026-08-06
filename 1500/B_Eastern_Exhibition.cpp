#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; i++){
            cin>>a[i]>>b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if(n%2 == 1) cout<<1<<endl;
        else{
            int mid = n/2;
            cout<< ((long long)(a[mid]-a[mid-1]+1) * (b[mid]-b[mid-1]+1)) <<endl;
        }
    }
    return 0;
}