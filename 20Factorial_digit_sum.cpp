/*
in 1000! its hard to store so we store numbere in form of digits like
3628800 → [0,0,8,8,2,6,3]

*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    const int MAXN = 1000;
    vector<int> fact(1,1);
    vector<int> digitSum(MAXN+1);

    digitSum[0] = 1;
    digitSum[1] = 1;

    for(int i=2;i<=MAXN;i++){
        int carry = 0;
        for(int j=0;j<fact.size();j++){
            int val = fact[j]*i + carry;
            fact[j] = val%10;
            carry = val/10;
        }

        while(carry){
            fact.push_back(carry%10);
            carry/=10;
        }

        int sum = 0;
        for(int d:fact) sum += d;
        digitSum[i] = sum;
    }

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;
        cout << digitSum[N] << "\n";
    }
}