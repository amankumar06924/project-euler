#include <iostream>
using namespace std;

long long sumEvenFib(long long n) {
    long long sum = 0;
    long long x1 = 1, x2 = 2;

    while (x2 <= n) {
        if (x2 % 2 == 0) {
            sum += x2;
        }
        long long next = x1 + x2;
        x1 = x2;
        x2 = next;
    }

    return sum;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
    long long n;
    cin >> n;
    cout << sumEvenFib(n) << endl;
    }
    return 0;
}