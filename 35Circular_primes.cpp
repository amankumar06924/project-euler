/** how i solve
 * the only main part of this problem to rotate the number 
 * so 
 * lets assume the given number is 12345
 * i just remove form last and come to first by 5*10^digitsize-1 + number/10 
 * it makes 51234 and check this number is prime or not by sieve algo that it.
 */

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000000 + 5;
vector<bool> prime(MX, true);

void sieve() {
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < MX; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MX; j += i)
                prime[j] = false;
        }
    }
}

bool isCircular(int n) {
    int d = log10(n) + 1;
    int pow10 = pow(10, d - 1);
    int rot = n;
    for (int i = 0; i < d; i++) {
        if (!prime[rot])
            return false;

        int last = rot % 10;
        rot = last * pow10 + rot / 10;
    }

    return true;
}

int main() {
    sieve();
    int N;
    cin >> N;
    long long sum = 0;
    for (int i = 2; i < N; i++) {
        if (prime[i] && isCircular(i))
            sum += i;
    }
    cout << sum << endl;

    return 0;
}