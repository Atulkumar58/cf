#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;

        // int c1=0, c2=0;
        vector<int> a(k, 0);
        for(int i=0; i<s.length(); i++){
            if(s[i] == '1'){
                a[i%k]++;
            }
        }

        bool possible = true;
        for(int i=0; i<k; i++){
            if(a[i] % 2 != 0){
                possible = false;
                break;
            }
        }

        if(possible) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}