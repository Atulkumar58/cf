#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> diff_a, diff_b;
vector<int> len_a, len_b;

vector<int> get_len(vector<int> & a){
    vector<int> len_a;
    int count = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] ==1) {
            count++;
        }else{
            if(i > 0 && a[i-1] == 1){
                len_a.push_back(count);
            }
            count = 0;
        }
    }
    if(count > 0){
        len_a.push_back(count);
    }
    return len_a;
}
vector<int> diff_sum(vector<int>& arr){
    int sum= 0;
    vector<int> res(arr.size()+1);
    res[arr.size()] = 0;
    for(int i= arr.size() - 1; i>=0; i--){
        sum += arr[i];
        res[i] = sum;
    }
    return res;
}
int calculate_count(vector<int>& arr, int num){
    int i= 0, j= arr.size() - 1;

    while(i <= j){
        int mid = (i + j) / 2;

        if(arr[mid] < num){
            i= mid + 1;
        }else{
            j= mid-1;
        }
    }
    return i;
}
int sum (int i, int j){
    // cout<<i<<" "<<j<<endl;
    int x= calculate_count(len_a, i);
    int s = diff_a[x];
    int temp= s - ((i-1) * (len_a.size() - x));

    int y= calculate_count(len_b, j);
     s = diff_b[y];
     int t= s - ((j-1) * (len_b.size() - y));
    //  cout<<temp<<" "<<t<<endl;
    return(temp *t);

}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }    
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    len_a = get_len(a);
    len_b = get_len(b);
    
    sort(len_a.begin(), len_a.end());
    sort(len_b.begin(), len_b.end());

    diff_a = diff_sum(len_a);
    diff_b = diff_sum(len_b);
    
    long long ans = 0;
    for(int i=1; i*i <= k; i++){
        if(k % i == 0){
            ans += sum(i, k/i);
            if(i* i != k) {
                ans += sum(k/i, i);
            }
            // cout<<i<<" "<<k/i<<" "<<ans<<endl;
        }
        
    }

    cout<<ans<<endl;
    return 0;
}