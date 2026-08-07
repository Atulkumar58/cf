#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        unordered_map<int,int> mp;
        int sum=0;

        for(int& i:a) {
            cin>>i;
            mp[i]++;
            sum+=i;
        }
        int maxi = 0;
        int num = 0;
        for(auto i:mp) {
            if(i.second > maxi) {
                maxi = i.second;
                num = i.first;
        }
    }
    int t= n-maxi;
        if(t + 2 < maxi){
            
            maxi-= (t+2);
            sum -= maxi*num;
            cout<<sum<<endl;
        }else {
            cout<<sum<<endl;
        }
         
}
    return 0;

}