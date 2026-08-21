#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;

    vector<pair<long long, long long>> v (1e6+2000, {0, 0});//left right
    vector<long long> lvl(2000);

    long long idx=1;
    long long sum=0;
    for(int i=1; idx<=1e6; i++){
        //i is size
        long long level_sum=0;
        for(int j=0; j<i; j++){
            level_sum += idx*idx;
            sum+= idx*idx;
            v[idx].first = level_sum;
            if(j!=0){
                v[idx].first += v[idx-i].first;
            }
            idx++;
        }
        lvl[i]= sum;
        level_sum=0;
        for(int j=1; j<=i; j++){
            level_sum += (idx-j)*(idx-j);
            v[idx-j].second = level_sum;
            if(j!=1){
                v[idx-j].second += v[idx-j-i+1].second;
            }
        }
    }

    while(t--){
        int n;
        cin>>n;
        //calculate the level or idx
        long long level = (sqrt(1+ 8*(n-1))-1)/2+1;
        long long total= lvl[level];
        if(n != (level*(level-1))/2+1){
            total -= v[n-1].first;
        }
        if(n != (level*(level+1))/2){
            total -= v[n+1].second;
        }
        cout<<total<<endl;
    }
    return 0;
}