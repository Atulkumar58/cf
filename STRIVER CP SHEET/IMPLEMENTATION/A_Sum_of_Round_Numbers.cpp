#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        int mask=1;
    vector<int> v;
        while(x){
            int p= x%10;
            if(p) v.push_back(p*mask);
            mask*=10;
            x/=10;
        }
        cout<<v.size()<<endl;
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }cout<<endl;
    }
return 0;
}