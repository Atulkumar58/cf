#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long pos; cin>>pos;

        int n= s.size();
        vector<bool> valid(n, true);
        vector<int> last(n, 0);
        last[0]=0;
        int l=0, r=1;
        for(int i=0; i<n-1; i++){
            if(pos <= n-i){
                break;
            }

            if(!valid[l]) l= last[l];
            while(r < n){
                if(!valid[l]){
                    last[r]= last[l];
                    l= r;
                    r++; 
                }
                if(r>=n) break;
                if(s[l] > s[r]){
                    valid[l]= false;
                    last[r]= last[l];
                    break;
                }

                last[r]= l;
                l=r;
                r++;
            }
            pos-= (n-i);
        }

        for(int i=0; i<n; i++){
            if(valid[i]){
                pos--;
                if(pos==0){
                    cout<<s[i];
                    break;
                }
            }
        }

    }
    return 0;
}