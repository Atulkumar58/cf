#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        int count=0;
        int ans= k;
        for(int i=0; i<k-1; i++) if(s[i] == 'W') count++;

        int i=0, j=k-1;
        while(j<n){
            if(s[j] == 'W') {count++;}
            ans= min(ans, count);
            if(s[i] == 'W') {count--;}

            i++, j++;
        }
        cout<<ans<<endl;
    }
    return 0;
}