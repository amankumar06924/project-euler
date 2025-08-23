#include<iostream>
#include<vector>
using namespace std;

double facto(int i) {
    if (i <= 1)
        return 1;

    return i * facto(i - 1);
}
int main() {
    int t;
    vector<double> an;
    cin >> t;
    for (int i = 0; i < t; i++) {
        double ans = 0;
        int a, b;
        cin >> a >> b;

        ans = (facto(b + a) / (facto(a) * facto(b)));
        an.push_back((double)ans);
        
    }
    cout.precision(0);
    for (double n : an) {
        cout << fixed << n << "\n";
    }
    return 0;
}