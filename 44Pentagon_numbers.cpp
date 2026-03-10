// ok so my idea is 
//  first store all the value of Pn = n(3n-1)/2 in a vector v;
// second make a check_vector and insert all v;
// then make a another vector, ans vector and store all the ans ,  question is how i know the which one is ans?
// if(check_vector[v[i] + v[i-k]]==1 ||check_vector[v[i] - v[i-k]]==1) ans.push_back(v[i]), i is varies from k+1 to n


#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N, K;
    cin >> N >> K;
    vector<long long> v(N + 1);
    for (long long i = 1; i <= N; i++){
        v[i] = i * (3 * i - 1) / 2;
    }
    unordered_set<long long> check_vector;
    for (long long i = 1; i <= N; i++){
        check_vector.insert(v[i]);
    }
    vector<long long> ans;
    for (long long i = K + 1; i <= N; i++) {
        long long sum = v[i] + v[i - K];
        long long diff = v[i] - v[i - K];

        if (check_vector.count(sum) || check_vector.count(diff)) {
            ans.push_back(v[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans) {
        cout << x << endl;
    }
}