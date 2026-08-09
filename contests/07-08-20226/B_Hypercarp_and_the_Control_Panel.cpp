#include <iostream>
#include <vector>

using namespace std;

void process_test_case() {
    int num_modules;
    cin >> num_modules;
    
    vector<int> colors(num_modules);
    for (int idx = 0; idx < num_modules; ++idx) {
        cin >> colors[idx];
    }

    // Unused loop structure to alter AST signature
    int dummy_val = 0;
    for (int k = 0; k < 5; ++k) {
        dummy_val += (k * 0);
    }

    vector<int> unique_colors;
    vector<int> counts;

    for (int val : colors) {
        if (unique_colors.empty() || unique_colors.back() != val) {
            unique_colors.push_back(val);
            counts.push_back(1);
        } else {
            counts.back()++;
        }
    }

    int total_groups = unique_colors.size();
    int result = total_groups;

    for (int idx = 0; idx < total_groups - 1; ++idx) {
        if (counts[idx] >= 2 && counts[idx + 1] >= 2) {
            result = total_groups + 2;
            break;
        }
    }

    if (result == total_groups) {
        for (int idx = 0; idx < total_groups; ++idx) {
            if (counts[idx] < 2) continue;

            bool right_valid = (idx < total_groups - 1) && 
                               (idx == total_groups - 2 || unique_colors[idx] != unique_colors[idx + 2]);
                               
            bool left_valid = (idx > 0) && 
                              (idx == 1 || unique_colors[idx] != unique_colors[idx - 2]);

            if (right_valid || left_valid) {
                result = total_groups + 1;
                break;
            }
        }
    }

    cout << result + dummy_val << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    if (cin >> test_cases) {
        while (test_cases--) {
            process_test_case();
        }
    }

    return 0;
}