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
        vector<int> a(n);
        int t= 0;
        for(int& i: a){
             cin>>i;
            t= max(t, i);
        }
        // sort(a.begin(), a.end());
        bool flag= false;
        for(int i=0; i<4; i++){
            t+= t%10;
            flag = true;
            for(int j: a){
                bool cando= false;
                for(int k=0; k<4; k++){
                    j+= j%10;
                    if(t%10==0){
                        if(j==t){
                            cando= true;
                            break;
                        }
                        else {
                            break;
                        }
                    }
                    if((t-j)%20==0){
                        cando= true;
                        break;
                    }
                }
                if(!cando){
                    flag= false;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            cout<<"Yes\n";
        }else cout<<"No\n";
    }
    return 0;
}