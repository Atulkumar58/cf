#include <iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> u(n);
        vector<int> s(n);
        for(int& i:u) cin>>i;
        for(int& i:s) cin>>i;

        unordered_map<int, vector<int>> freq;
        for(int i=0; i<n; i++){
            freq[u[i]].push_back(s[i]);
        }
        unordered_map<int,vector<long long>> skills;
        for(auto& p: freq){
            sort(p.second.begin(), p.second.end(), greater<int>());
            vector<long long> temp;
            long long sum=0;
            for(long long i: p.second){
                sum+= i;
                temp.push_back(sum);
            }
            skills[p.first] = temp;
        }
        vector<long long> ans(n + 1, 0);

// 2. Loop through each university just ONCE
for(auto& p: skills){
    const auto& v = p.second;
    int total_students = v.size();
    
    // This university can only contribute to team sizes up to its student count
    for(int k = 1; k <= total_students; k++){
        int take = total_students - (total_students % k);
        if (take > 0) {
            ans[k] += v[take - 1]; // Directly add to the global answer for team size k
        }
    }
}

// 3. Print the accumulated answers from 1 to n
for(int k = 1; k <= n; k++){
    cout << ans[k] << " ";
}
cout << "\n";
    }
    return 0;
}