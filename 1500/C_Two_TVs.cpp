#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int n;cin>>n;
    vector<pair<int, int>> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(), a.end());
    bool possible= true;
    int last[2]= {-1, -1};
    for(int i=0; i<n; i++){
        if(a[i].first > last[0]){
            last[0]= a[i].second;
        }
        else if(a[i].first > last[1]){
            last[1]= a[i].second;
        }
        else{
            possible= false;
            break;
        }
    }
    if(possible) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}