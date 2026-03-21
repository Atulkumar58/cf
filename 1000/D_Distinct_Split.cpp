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
        string s;
        cin>>s;
        vector<bool> a(26, false);
        int diff=0;
        vector<int> b_freq(n);
        for(int i=n-1; i>=0; i--){
            int c= s[i]-'a';
            b_freq[i]= diff;
            if(!a[c]){
                a[c]= true;
                diff++;
            }
        }

        a= vector<bool>(26, false);
        diff=0;
        int ans=0;
        for(int i=0; i<n; i++){
            int c= s[i]-'a';
            if(!a[c]){
                a[c]= true;
                diff++;
            }
            ans= max(ans, diff+b_freq[i]);
    }
        cout<<ans<<endl;
    }
    return 0;
}