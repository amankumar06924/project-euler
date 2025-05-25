#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    long long sum = 0;
    for (const string &num : numbers) {
        sum += stoll(num.substr(0, 12));
    }
    string result = to_string(sum);
    cout << result.substr(0, 10) << endl;

    return 0;
}