/*
The square root of 2 can be written as an infinite continued fraction:

    √2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... )))

Key Observation
Each new fraction follows a fixed recurrence relation.
If current fraction is:
    n / d
Then the next fraction becomes:

    new_n = n + 2*d
    new_d = n + d

Example
    n = 3, d = 2
    new_n = 3 + 2×2 = 7
    new_d = 3 + 2   = 5
    fraction = 7/5

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> a, vector<int> b){
    vector<int> res;
    int carry = 0;

    int n = max(a.size(), b.size());

    for(int i = 0; i < n || carry; i++){
        int sum = carry;
        if(i < a.size()) sum += a[i];
        if(i < b.size()) sum += b[i];
        res.push_back(sum % 10);
        carry = sum / 10;
    }

    return res;
}

vector<int> mul2(vector<int> a){
    vector<int> res;
    int carry = 0;

    for(int i = 0; i < a.size() || carry; i++){
        int val = carry;

        if(i < a.size()) val += 2 * a[i];
        res.push_back(val % 10);
        carry = val / 10;
    }
    return res;
}

int main(){

    int N;
    cin >> N;

    vector<int> n = {3};
    vector<int> d = {2}; 

    for(int i = 1; i <= N; i++){

        if(n.size() > d.size()){
            cout << i << endl;
        }

        vector<int> new_n = add(n, mul2(d));
        vector<int> new_d = add(n, d);

        n = new_n;
        d = new_d;
    }

    return 0;
}