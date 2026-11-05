#include <iostream>
#include <vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<pair<char, int>> a(3);
        a[0].first='P';
        a[1].first='R';
        a[2].first='S';
        int sum=0;
        int max=0;
        char maxch='p';
        for(int i=0;i<3;i++){
            cin>>a[i].second;
            if(a[i].second>max){
                max=a[i].second;
                maxch=a[i].first;
            }
            sum+=a[i].second;
        }  
        
        for(int i=0; i<sum; i++){
            cout<<maxch;
        }cout<<endl;
    }
return 0;
}   