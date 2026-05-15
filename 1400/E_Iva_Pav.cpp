#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int& i:a) cin>>i;

        vector<vector<int>> v(n+1, vector<int>(31,0));
        for(int i=1; i<n+1; i++){
            int t= a[i-1];
            for(int j=0; j<31; j++){
                if(!(t&1)) v[i][j]= v[i-1][j] + 1;
                else v[i][j]= v[i-1][j];
                t>>=1;
            }
        }

        int q;
        cin>>q;
        while(q--){
            int l, k;
            cin>>l>>k;

            int s= l, e= n;
            while(s<=e){
                int m= (s+e)/2;
                int c= 0;
                for(int i=30; i>=0; i--){
                    c<<=1;
                    if(v[m][i] - v[l-1][i] == 0) c+=1;
                }
                // cout<<c<<" "<<m<<"  ";
                if(c>=k) s= m + 1;
                else e= m -1;
            }
            if(l <= e)cout<<e<<" ";
            else cout<<-1<<" ";
        }
        cout<<endl;
    }
    return 0;
}