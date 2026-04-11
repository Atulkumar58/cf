#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<char>> arr(n, vector<char>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }

        int i=0, j=0;
        int ans=0;
        while(j < n/2){
            for(int i=j; i < n-j-1; i++){
                int c=0;
                if(arr[j][i] == '1') c++;
                if(arr[i][n-j-1] == '1') c++;
                if(arr[n-j-1][n-i-1] == '1') c++;
                if(arr[n-i-1][j] == '1') c++;

                ans += min(c, 4-c);
            }
            j++;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}