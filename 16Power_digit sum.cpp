/**
 * ok so you can't use (1<<n) because of n is 1e4 and you can only shift bits upto 62 so this approach cant apply here 
 * so we use normal implemention to store digit by digit and at end calculate total sum;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> num;
        num.push_back(1);

        for(int i = 0; i < n; i++) {
            int carry = 0;
            for(int j = 0; j < num.size(); j++) {
                int val = num[j] * 2 + carry;
                num[j] = val % 10;
                carry = val / 10;
            }

            while(carry) {
                num.push_back(carry % 10);
                carry /= 10;
            }
        }
        int sum = 0;
        for(int d : num) sum += d;

        cout << sum << endl;
    }

    return 0;
}