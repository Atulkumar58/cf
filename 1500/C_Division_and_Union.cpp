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
            segment.push_back({l,r,i});
        }
        sort(segment.begin(), segment.end());

        vector<int> ans(n);
        ans[segment[0][2]] = 1;
        int last[2] = {segment[0][1], -1};
        bool possible = false;
        for(int i=1; i<n; i++){
            int v=ans[segment[i-1][2]];
            if(segment[i][0] <= segment[i-1][1] || last[v-1] >= segment[i][0]){
                // Overlapping segments, assign the same group
                ans[segment[i][2]] = v;
                last[v-1] = max(last[v-1], segment[i][1]);
            }
            else{
                // Non-overlapping segments, assign a different group
                v= 3-v;
                ans[segment[i][2]] = v; // Toggle between 1 and 2
                last[v-1] = max(last[v-1], segment[i][1]);
                possible = true;
            }
        }
        
        if(!possible){
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