#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        unordered_map<int, int> freq;
        int count= 1;
        int ans=0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(i >0){
                if(a[i] != a[i-1]){
                    freq[a[i-1]] = max(freq[a[i-1]], count);
                    ans= max(ans, count);
                    count= 1;
                }
                else{
                    count++;
                }
            }
        }
        freq[a[n-1]] = max(freq[a[n-1]], count);
        ans= max(ans, count);

        int b[n];
        count= 1;
        for(int i=0; i<n; i++){
            cin>>b[i];
            if(i >0){
                if(b[i] != b[i-1]){
                    ans= max(ans, freq[b[i-1]] + count);
                    // freq[b[i-1]] = max(freq[b[i-1]], count);
                    count= 1;
                }
                else{
                    count++;
                }
            }
        }
        ans= max(ans, freq[b[n-1]] + count);

        cout<<ans<<endl;
    }
    return 0;
}