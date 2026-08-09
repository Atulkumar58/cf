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
        vector<vector<int>> segment;
        for(int i=0; i<n; i++){
            int l,r;
            cin>>l>>r;
            segment.push_back({l,r});
        }
        sort(segment.begin(), segment.end());

        vector<int> ans(n);
        ans[0] = 1;
        int last[2] = {segment[0][1], -1};
        bool possible = false;
        for(int i=1; i<n; i++){
            if(ans[i-1] == 1){
                if(segment[i][0] > last[1]){
                    ans[i]= 3-ans[i-1];
                    last[1] = segment[i][1];
                }
                else{
                    ans[i] = ans[i-1];
                    last[0]= max(last[0], segment[i][1]);
                }
            }
            else{
                if(segment[i][0] > last[0]){
                    ans[i]= 3-ans[i-1];
                    last[0] = segment[i][1]; 
                }
                else{
                    ans[i]= ans[i-1];
                    last[1]= max(last[1], segment[i][1]);
                }
            }
            
        }
        // for(int i=0; i<n; i++)cout<<ans[i]<<" ";
        // cout<<endl;

        if(last[1] == -1){
            cout<<-1<<endl;
        }
        else{
            for(int i=0; i<n; i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}