#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> a(n, vector<int>(m));
    unordered_map<int, int> freq;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            
            freq[a[i][j]]++;
        }
    }

    long long sum = 0;
    long long current_sum = 0;
    unordered_map<int, int> current_freq;
    for(int i=0; i<n; i++){
        unordered_map<int, int> row_freq;
        for(int j=0; j<m; j++){
            row_freq[a[i][j]]++;
        }
        for(auto& p : row_freq){
            int num = p.first;
            int count = p.second;
            int c= current_freq[num];
            int f= freq[num];
            current_freq[num] += count;
            current_sum -= (long long)c*(f-c);
            current_sum += (long long)(count+c) * (f-count-c);
        }
        sum += current_sum;
    }

    current_sum = 0;
    current_freq.clear();
    for(int j=0; j<m; j++){
        unordered_map<int, int> col_freq;
        for(int i=0; i<n; i++){
            col_freq[a[i][j]]++;
        }
        for(auto& p : col_freq){
            int num = p.first;
            int count = p.second;
            int c= current_freq[num];
            int f= freq[num];
            current_freq[num] += count;
            current_sum -= (long long)c*(f-c);
            current_sum += (long long)(count+c) * (f-count-c);
        }
        sum += current_sum;
    }
    cout<<sum<<endl;

    return 0;
}