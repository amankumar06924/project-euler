#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    long long max_product = 0;

    for (int i = 0; i <= n - k; i++) {
        long long product = 1;
        for (int j = i; j < i + k; j++) {
            product *= (s[j] - '0');
        }
        max_product = max(max_product, product);
    }

    cout << max_product << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}