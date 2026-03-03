#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        long long n = ((N - 1) / 2) % mod; 
        long long ans = 0;
        long long inv3 = 333333336;
        long long n_sq = (n * n) % mod;
        long long inner = (4 * n_sq - 1 + mod) % mod;
        long long term1 = (n * inner) % mod;
        long long term1_final = (4 * term1) % mod;
        long long part1 = (term1_final * inv3) % mod;
        long long part2 = (10 * ((n * (n + 1)) % mod)) % mod;
        ans = (part1 + part2 + 1) % mod;
        cout << ans << endl;
    }
    return 0;
}