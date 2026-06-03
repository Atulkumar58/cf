#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> arrs(n);
        int smallest= 1e9;
        int smallest2= 1e9;
        long long ans= 0;
        for(int i=0; i<n; i++){
            int m;
            cin>>m;
            arrs[i].resize(m);
            int a=1e9, b=1e9;
            for(int j=0; j<m; j++){
                cin>>arrs[i][j];
                if(arrs[i][j] < a){
                    b= a;
                    a= arrs[i][j];
                }
                else if(arrs[i][j] < b){
                    b= arrs[i][j];
                }
                smallest= min(smallest, arrs[i][j]);
            }
            ans+=b;
            smallest2= min(smallest2, b);
        }
        cout<<ans - smallest2 + smallest<<endl;

    }
    return 0;
}