#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int a0 = 0; a0 < t; a0++) {
        int n;
        cin >> n;
        long long sum = 0;
        
        for(int i = 1; i < n; i++) {
            if(i % 3 == 0 || i % 5 == 0) {
                sum += i;
            }
        }
        
        cout << sum << endl;
    }
    
    return 0;
}
