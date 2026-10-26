#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        char c; cin>>c;
        string s; cin>>s;
        int i=0, j=n-1;
        int ans=0;
        while(i<j){
            if(s[i] != s[j]){
                if(s[i] != c && s[j] != c){
                    ans+=2;
                }
                else{
                    ans++;
                }
            }
            i++, j--;
        }
        cout<<ans<<endl;
    }
    return 0;
}