#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(2*n);
        // int maxi=0;
        vector<int> index(n+1, -1);
        vector<long long> sum(2*n, 0);
        for(int i=0; i<2*n; i++){
            cin>>a[i];
            if(index[a[i]]==-1){
                index[a[i]]=i;
                if(i == 0) sum[i]=1;
                else sum[i]= sum[i-1]+1;
            }
            else {
                long long len = i - index[a[i]] + 1; // Storing as long long prevents overflow
                long long squared_score = len * len;
                
                if (index[a[i]] > 0) {
                    sum[i] = max(sum[i-1] + 1, sum[index[a[i]] - 1] + squared_score);
                } else {
                    sum[i] = max(sum[i-1] + 1, squared_score);
                }
            }
        }

        cout<< sum[2*n - 1]<<endl;
    }
    return 0;
}