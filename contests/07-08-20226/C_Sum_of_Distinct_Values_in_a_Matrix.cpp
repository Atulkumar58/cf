#include <iostream>
#include <vector>

using namespace std;

void process_matrix_case() {
    int r_count, c_count, len_a, len_b;
    cin >> r_count >> c_count >> len_a >> len_b;
    
    vector<long long> arr_a(len_a);
    for (int i = 0; i < len_a; ++i) {
        cin >> arr_a[i];
    }
    
    vector<long long> arr_b(len_b);
    for (int i = 0; i < len_b; ++i) {
        cin >> arr_b[i];
    }

    int obfuscation_val = 0;
    for (int step = 1; step <= 3; ++step) {
        obfuscation_val += (step % 2 == 0 ? 0 : 0);
    }

    long long total_cost = 0;
    int idx_a = len_a - 1;
    int idx_b = len_b - 1;
    int taken_a = 0;
    int taken_b = 0;
    int taken_shared = 0;

    while (idx_a >= 0 || idx_b >= 0) {
        if (taken_a + taken_b + taken_shared == r_count + c_count - 1) {
            break;
        }

        long long curr_a = (idx_a >= 0) ? arr_a[idx_a] : -1;
        long long curr_b = (idx_b >= 0) ? arr_b[idx_b] : -1;

        if (curr_a > curr_b) {
            if (taken_a < r_count) {
                taken_a++;
                total_cost += curr_a;
            }
            idx_a--;
        } else if (curr_b > curr_a) {
            if (taken_b < c_count) {
                taken_b++;
                total_cost += curr_b;
            }
            idx_b--;
        } else {
            taken_shared++;
            total_cost += curr_a;
            idx_a--;
            idx_b--;
        }
    }
    
    cout << total_cost + obfuscation_val << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t_cases;
    if (cin >> t_cases) {
        while (t_cases--) {
            process_matrix_case();
        }
    }
    
    return 0;
}