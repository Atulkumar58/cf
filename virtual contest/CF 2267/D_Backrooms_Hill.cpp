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
        vector<int> e;
        vector<int> o;
        for(int i=0; i<n; i++){
            int t;
            cin>>t;
            cout<<t<<" ";
            if(i%2==0){
                e.push_back(t);
            }else{
                o.push_back(t);
            }
        }
        sort(e.begin(), e.end());
        sort(o.begin(), o.end());

        int i=0, j= n-1;
        int idx0=0, idx1=0;
        vector<int> ans(n);
        bool flag = true;
        while(i<=j){
            if(e[idx0] < o[idx1]){
                if(i%2==0 && (i==0 || ans[i-1] < e[idx0])){
                    ans[i] = e[idx0];
                    i++;
                }else if(j%2==0 && (j== n-1 || ans[j+1] < e[idx0])){
                    ans[j] = e[idx0];j--;
                }
                else{
                    flag= false;
                    break;
                }
                idx0++;
            }
            else if(e[idx0] > o[idx1]){
                if(i%2!=0 && (i==0 || ans[i-1] < o[idx1])){
                    ans[i] = o[idx1];
                    i++;
                }
                else if(j%2!=0 && (j== n-1 || ans[j+1] < o[idx1])){
                    ans[j] = o[idx1];
                    j--;
                }
                else{
                    flag= false;
                    break;
                }
                idx1++;
            }
            else{
                flag= false;
                break;
            }
        }
        cout<<(flag? "YES\n":"NO\n");

    }
}