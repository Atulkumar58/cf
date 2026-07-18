#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // If k >= n, we can just cover each segment with a tape of length 1.
    if (k >= n) {
        cout << n << endl;
        return 0;
    }

    // Calculate gaps between adjacent segments
    vector<int> gaps;
    for (int i = 0; i < n - 1; i++) {
        gaps.push_back(arr[i+1] - arr[i] - 1);
    }

    // Sort gaps to remove the largest ones
    sort(gaps.rbegin(), gaps.rend());

    // Start with the length if we used 1 big tape
    int total_length = arr[n - 1] - arr[0] + 1;

    // Subtract the k-1 largest gaps
    for (int i = 0; i < k - 1; i++) {
        total_length -= gaps[i];
    }

    cout << total_length << endl;
    return 0;
}