// similar problem to  math + two sum 

#include<bits/stdc++.h>
using namespace std;
vector<int> v;
bool is_abundant[28125] = {false}; 
void div() {
    for (int i = 1; i <= 28123; i++) {
        long long sum = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                if (j < i) sum += j;
                int paired = i / j;
                if (paired != j && paired < i) sum += paired; 
            }
        }
        if (sum > i) {
            v.push_back(i);
            is_abundant[i] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    div();
    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            if (n > 28123) {
                cout << "YES\n";
                continue;
            }
            bool flag = false;
            for (int i = 0; i < v.size(); ++i) {
                if (v[i] > n) break; 
                int complement = n - v[i];
                if (is_abundant[complement]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
