#include <iostream>
using namespace std;

int fun(string s, int idx){
    bool possible = true;
        bool q= 1;
        
        for(int i=idx; i<s.length(); i+=2){
            //check if all char ques
            if(s[i] != '?'){
                q = 0;
            }

            if(i+2<s.length() && s[i] == s[i+2] && s[i] != '?' && s[i+2] != '?'){
                possible = false;
                break;
            }

            if(s[i+2] == '?' && s[i] != '?'){
                s[i+2] = (s[i] == '1') ? '0' : '1';
            }
        }

        int ans=0;
        if(possible) {
            if(q) ans=2;
            else ans=1;
        }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        int ans= fun(s, 0);
        // cout<<ans<<" ";
        ans *= fun(s, 1);

        cout<<ans<<endl;
    }
    return 0;
}