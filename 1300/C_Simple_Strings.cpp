#include <iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    for(int i=1;i<s.size();i++){
        if(s[i-1]==s[i]){
            char newchar= (s[i-1]-'a'+1) % 26 + 'a';
            if(i+1 < s.size() && s[i+1]==newchar){
                s[i]= (newchar-'a'+1) % 26 + 'a';
            }
            else{
                s[i]=newchar;
            }
        }
    }
    cout<<s;
    return 0;
}