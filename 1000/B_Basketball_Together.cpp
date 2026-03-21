#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, d;
    cin>>n>>d;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());
    int ans=0;
    int i=0, j=n-1;
    while(i<=j){
        int c= d/a[j];

        if(c==0){
            ans++;
            j--;
        }
       else if(i+c <= j){
            i+=c;
            ans++;
            j--;
       }
       else break;
    }
    cout<<ans<<endl;
    return 0;
}