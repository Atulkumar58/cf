#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    a[n] = 0;
    long long sum=0;
    vector<int> maxi(2, n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum += a[i];
        if(a[i] > a[maxi[0]]){
            maxi[1]=maxi[0];
            maxi[0]=i;
        }
        else if(a[i] > a[maxi[1]]){
            maxi[1]=i;
        }
    }

    vector<int> ans;
    // cout<<maxi[0]<<" "<<maxi[1]<<endl;
    for(int i=0; i<n; i++){
        if(sum- a[i] == 2* a[maxi[0]] && i != maxi[0]){
             ans.push_back(i+1);
        }
        else if(sum- a[i] == 2* a[maxi[1]] && i != maxi[1]){
             ans.push_back(i+1);
        }
    }
    cout<<ans.size()<<endl;
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}