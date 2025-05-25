#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long number;
        cin >> number;
        long long sum_of_squares = (number * (number + 1) * (2 * number + 1)) / 6;
        long long sum = (number * (number + 1)) / 2;
        long long square_of_sum = sum * sum;

        cout << square_of_sum - sum_of_squares << endl;
    }

    return 0;
}

// pow() this function return float value so it avoid to use in it