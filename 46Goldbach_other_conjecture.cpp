/**
 * given information,  n and n = a + 2*b^2
 * so we can write given information like this
 * p + 2*P1^2 = n
 * p1 = sqrt((n-p)/2); here p is prime 
 * we iterate all prime p, p<n and check
 * if p1 is perfect square this it give a solution thats it;
 * 
 */

#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 500000;
vector<bool> is_prime(MAX_N + 1, true);
vector<int> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= MAX_N; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAX_N; i += p)
                is_prime[i] = false;
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}
bool isPerfectSquare(long long x) {
    if (x < 0) return false;
    if (x == 0) return true;
    long long s = round(sqrt(x));
    return s * s == x;
}
void solve() {
    int n;
    if (!(cin >> n)) return;
    int count = 0;
    for (int p : primes) {
        if (p >= n) break;
        int remainder = n - p;
        if (remainder % 2 == 0) {
            if (isPerfectSquare(remainder / 2)) {
                count++;
            }
        }
    }
    cout << count << endl;
}

int main() {
    sieve();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}