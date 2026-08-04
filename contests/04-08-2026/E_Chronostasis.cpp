#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        map<long long, int> m;
        int start = INT_MAX;
        long long sum=0;
        for(int& i: a){
            cin>>i;
            sum += i;
            m[i] ++;
            if(i > 0 && start > i){
                start = i;
            }
        }
        
        if(sum <= 0){
            cout<< -1 <<endl;
            continue;
        }
        vector<long long> ans;
        ans.push_back(start);
        if(m[start]==1) m.erase(start);
        else m[start]--;

        for(int i=1; i<n; i++){
            long long l= ans.back();
            auto it= m.find(-l);
            if(it == m.end()){
                m[-l]=0;
                it=m.find(-l);
                it++;
                ans.push_back(l + it->first);
                it->second--;
                if(it->second == 0){
                    m.erase(it->first);
                }
                m.erase(-l);
            }else{
                it++;
                ans.push_back(l+it->first);
                it->second--;
                if(it->second == 0){
                    m.erase(it->first);
                }
            }
        }
        for(long long i: ans) cout<<i<<" ";
        cout<<endl;
        
    }
    return 0;
}