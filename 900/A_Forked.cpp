#include <iostream>
using namespace std;

int a, b;
int xi, yi;
int xj, yj;
int m[8]={-1,-1, 1, 1};
int n[8]={1, -1, 1, -1};
bool check(int x, int y){
    pair<int, int> p= {abs(x-xj), abs(y-yj)};
    if(p.first== a && p.second ==b) return true;
    if(p.second==a && p.first ==b) return 1;
    return false;
}
int solve(){
    int ans=0;
    for(int i=0; i<4; i++){
        int nx= xi+(m[i]*a), ny= yi+(n[i]*b);
        ans+= check(nx, ny);
        // cout<<nx<<" "<<ny<<"\n";
        nx= xi+(m[i]*b), ny= yi+(n[i]*a);
        if(a!=b)
        ans+= check(nx, ny);
        //  cout<<nx<<" "<<ny<<"\n";

    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        cin>>xi>>yi;
        cin>>xj>>yj;

        cout<<solve()<<endl;
    }
    return 0;
}