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
        for(int&i:a){
            cin>>i;
        }

        int sum=0;
        int flag= 0;
        vector<int> ans={a[0]};
        for(int i=1; i<n; i++){
            if(a[i]>a[i-1]){
                if(flag == -1){
                    ans.push_back(a[i-1]);
                }
                flag=1;
            }else{
                if(flag==1){
                    ans.push_back(a[i-1]);
                }
                flag= -1;
            }
        }
        cout<<ans.size()+1<<endl;
        for(int i:ans){
            cout<<i<<" ";
        }if(ans.back() != a.back()) cout<<a.back()<<" ";
        cout<<endl;

    }
    return 0;
}