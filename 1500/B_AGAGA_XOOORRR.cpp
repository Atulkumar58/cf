#include <iostream>
#include <vector>

using namespace std;
vector<int> a;
int check(int i, int x){
    if(i == a.size()){
        return 0;
    }
    int t=0;
    while(i < a.size() && t != x){
        t^=a[i];
        i++;
    }
    if(t == 0){
        return 0;
    }
    return check(i, x)+1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        a.resize(n);
        int x=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            x^=a[i];
        }

        if(x == 0){
            cout<<"YES"<<endl;
        }
        else{
            if(check(0, x) >= 2){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
            
        }


    }
    return 0;
}