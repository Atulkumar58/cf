#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> endings;
long long ans=0;

void conquer(int i, int j){
    int mid = (i+j)/2;
    vector<int> temp;

    int left = i, right = mid+1;
    while(left <= mid && right <= j){
        if(endings[left] <= endings[right]){
            temp.push_back(endings[left]);
            left++;
        } else {
            temp.push_back(endings[right]);
            ans += (mid - left + 1); // Count inversions
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(endings[left]);
        left++;
    }
    while(right <= j){
        temp.push_back(endings[right]);
        right++;
    }

    for(int k = i; k <= j; k++){
        endings[k] = temp[k - i];
    }
    // delete[] temp;
}
void divide(int i, int j){
    if(i == j) return;
    int mid = (i+j)/2;

    divide(i, mid);
    divide(mid+1, j);

    conquer(i, j);

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> intervals(n, vector<int>(2));
        for(int i=0; i<n; i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }

        sort(intervals.begin(), intervals.end());
        // Process the sorted intervals
        endings.clear();
        for(int i=0; i<n; i++){
            endings.push_back(intervals[i][1]);
        }
        ans=0;
        divide(0, n-1);
        
        cout<<ans<<endl;
    }
    return 0;
}