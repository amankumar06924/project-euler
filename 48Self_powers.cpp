/*
Key Observation
We only need the LAST 10 DIGITS of the result.

Instead of computing huge numbers like i^i (which can have millions
of digits), we compute everything modulo 10^10.
Why?
Because:
    last k digits of a number = number % (10^k)
So for last 10 digits:
    MOD = 10^10

Core Idea
For each i from 1 to n:
    value = (i^i) % MOD
Add it to answer:
    ans = (ans + value) % MOD
*/

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 10000000000LL;

long long modpow(long long a, long long b) {
    long long res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = (__int128)res * a % MOD;
        a = (__int128)a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main() {

    long long n;
    cin >> n;
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        ans = (ans + modpow(i, i)) % MOD;
    }
    cout << ans << endl;
}