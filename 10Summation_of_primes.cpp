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
    int i = 0;
    long long sum = 0;
  while (primes[i]<=n)
  {
    sum += primes[i];
    i++;
  }
  cout<<sum<<endl;
}

int main() {
    int t;
    cin >> t;
    vector<int> primes = sieve(1050000);
    while (t--) {
        solve(primes);
    }
    return 0;
}
