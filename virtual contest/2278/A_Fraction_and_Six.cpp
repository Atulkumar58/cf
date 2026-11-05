#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string a;
        cin>>a;
        string b;
        cin>>b;
        vector<int> freq(26,0);
        for(char ch: a) freq[ch-'a']++;
        for(char ch: b) freq[ch-'a']--;

        string ans = "six";
        for(char ch: ans){
            freq[ch-'a']--;
        }
        bool possible= true;
        for(int i=0; i<26; i++){
            if(freq[i]!=0){
                cout<<"NO"<<endl;
                possible = false;
                break;
            }
        }
        if(possible)
        cout<<"YES"<<endl;
    }
    return 0;
}