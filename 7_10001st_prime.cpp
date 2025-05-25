#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

void solve(const vector<int>& primes) {
    int n;
    cin >> n;
    if (n <= primes.size()) {
        cout << primes[n - 1] << endl;
    } else {
        cout << "Input too large" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    vector<int> primes = sieve(105000);
    while (t--) {
        solve(primes);
    }
    return 0;
}
