#include <bits/stdc++.h>
using namespace std;

long long maxPrimeFactor(long long n) {
    long long max_factor = -1;
    
    while (n % 2 == 0) {
        max_factor = 2;
        n /= 2;
    }

    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            max_factor = i;
            n /= i;
        }
    }

    if (n > 1)
        max_factor = n;
    
    return max_factor;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << maxPrimeFactor(n) << endl;
    }
    return 0;
}