#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> o;
        vector<int> e;
        int count_neg = 0;
        int countze = 0;
        int countzo = 0;
        long long sum = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum += abs(a[i]);
            if(i%2 == 0){
                e.push_back(abs(a[i]));
                if(a[i]<0) count_neg++;
                else if(a[i] == 0) countze++;
            } 
            else{
                o.push_back(abs(a[i]));
                if(a[i] <0) count_neg--;
                else if(a[i] == 0) countzo++;
            } 
            a[i] = abs(a[i]);
        } 

        sort(e.begin(), e.end());
        sort(o.begin(), o.end());

        if(count_neg > 0){
            for(int i=0; i<count_neg - countzo; i++){
                sum -= 2*e[i];
            }
            cout<<sum<<endl;
        }
        else{
            for(int i=0; i<-count_neg - countze; i++){
                sum -= 2*o[i];
            }
            cout<<sum<<endl;
        }
    }
}