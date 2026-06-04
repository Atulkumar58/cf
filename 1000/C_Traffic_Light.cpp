#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char c;
        cin>>c;
        string s;
        cin>>s;
        int count=0;
        unordered_map<char, int> mp;
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'g'){
                count=0;
            }
            else{
                count++;
            }
            mp[s[i]]=max(mp[s[i]], count);
        }   
        for(int i= n-1; i>=0; i--){
            if(s[i] == 'g'){
                count=0;
                break;
            }
            else{
                count++;
            }
            mp[s[i]]=max(mp[s[i]], count);
        }
        cout<<mp[c]<<endl;
    }
    return 0;
}