#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool static costom(const vector<int>& a, const vector<int>& b) {
    if(a[0] == b[0]){
        return a[1] > b[1];
    }
    return a[0] < b[0];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> seg(n, vector<int>(3));
    for(int i=0; i<n; i++){
        cin>>seg[i][0]>>seg[i][1];
        seg[i][2] = i+1;
    }
    sort(seg.begin(), seg.end(), costom);

    int last=-1, till=0;
    for(int i=0; i<n; i++){
        if(seg[i][1] <= till){
            cout<<seg[i][2]<<" "<<seg[last][2]<<endl;
            return 0;
        }
        else{
            if(till < seg[i][1]){
                till= seg[i][1];
                last= i;
            }
        }
    }
    cout<<-1<<" "<<-1<<endl;
    return 0;
}