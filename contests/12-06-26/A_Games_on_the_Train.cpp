#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int m= INT_MIN;
        int x= INT_MAX;
        for(int& i: a) {
            cin>>i;
            m= max(m, i);
            x= min(x, i);
        }
        cout<<m-x+1<<endl;
    }
    return 0;
}