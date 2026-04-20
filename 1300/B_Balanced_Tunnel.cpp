#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int& i: a) cin>>i;
    for(int& i: b) cin>>i;

    int ans=0;
    vector<bool> found(n+1, false);
    int i=0, j=0;
    while(i < n){
        if(a[i]==b[j]){
            i++, j++;
        }
        else{
            if(found[a[i]]) i++;
            else{
                found[b[j]] = true;
                ans++;
                j++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}