#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int mini= INT_MAX;
        int maxi= INT_MIN;
        int maxjump=0;
        vector<int> pos;
        vector<int> neg;
        for(int& x: a) {
            cin>>x;
            if(x>0) pos.push_back(x);
            else neg.push_back(-x);
            mini= min(mini, x);
            maxi= max(maxi, x);
            maxjump= max(maxjump, abs(x));
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());

        if(maxi-mini <= maxjump){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
            int s=0, l=0;
            int sum=0;
            int i=0, j=0;
            int idx=0;
            while(idx < n){
                if(i<pos.size() && sum + pos[i] < s+maxi-mini){
                    cout<<pos[i]<<" ";
                    sum += pos[i];
                    i++;
                }else{
                    cout<<-neg[j]<<" ";
                    sum -= neg[j];
                    j++;
                }
                idx++;
            }
            cout<<endl;
        }
    }
}