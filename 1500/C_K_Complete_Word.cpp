#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
vector<int> freq;
void insert(char c){
    freq[c-'a']++;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;

        vector<bool> vis(n, 0);
        freq.resize(26, 0);
        int ans=0;
        for(int i=0; i<k; i++){
            if(!vis[i]){
                for(int& i: freq) i= 0;
                
                int count=0;
                for(int j= i; j<n; j+= k){
                    insert(s[j]);
                    vis[j]= 1;
                    count++;
                }

                if(!vis[n-1-i]){
                    for(int j= n-1-i; j>=0; j-= k){
                        insert(s[j]);
                        vis[j]= 1;
                        count++;
                    }
                }

                int t=INT_MIN;
                for(int i: freq){
                    t= max(t, i);
                }
                
                ans+= count-t;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}