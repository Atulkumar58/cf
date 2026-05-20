#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // cout<<n<<endl;
        string s;
        cin>>s;
        
        vector<int> pos;
        for(int i=0; i<n; i++){
            if(s[i] == '*') pos.push_back(i);
        }
        if(pos.empty()){
            cout<<0<<endl;
            continue;
        }
        int m = pos.size();
        int median = pos[(m-1)/2];
        long long moves = 0;
        int idx= median - (m-1)/2;
        for(int i=0; i<m; i++){
            moves += abs(pos[i] - idx);
            idx++;
        }
        cout<<moves<<endl;
    }
    return 0;
}