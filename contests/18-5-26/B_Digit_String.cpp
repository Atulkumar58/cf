#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        int four = 0;
        int twos = 0;

    for (char c : s) {
        if (c == '4') {
            four++;
        } else if (c == '2') {
            twos++;
        }
    }

    int odd_l = 0;
    int two_l = 0;
    int min_remove = twos; 
    for (char c : s) {
        if (c == '4') continue; 

        if (c == '1' || c == '3') {
            odd_l++;
        } else if (c == '2') {
            two_l++;
        }
        int two_r = twos - two_l;
        min_remove = min(min_remove, odd_l + two_r);
    }
    cout << four + min_remove << "\n";
    }
    return 0;
}