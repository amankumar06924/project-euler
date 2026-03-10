/**
 * ok so my idea is 
 * i interate from 1 to N 
 * if we are given 3 and 5 
 * so i check if sqrt(1+8i) is perfect square and (sqrt(1+8i)-1)/2 should be integer then it is part of solution and push it into ans vector 
 * if we are given 5 and 6
 * so i check if sqrt(1+24i) is perfect square and (sqrt(1+24i)+1)/6 should be integer then it is part of solution and push it into ans vector 
 * then print all element of ans vector
 * 
 */

 /** 
  * ok so main question is how i know this part give you a solution (sqrt(1+8i) is perfect square and (sqrt(1+8i)-1)/2)
  * first case is Tn = Pn , and give the Tn = n(n+1)/2 , Pn = n(3n-1)/2
  * n(n+1)/2 = r(3r-1)/2 , lets r(3r-1)/2 = c
  * then the equation become n^2 + n -2c = 0;  
  * the solution of this equation is,  alpha =  (sqrt(1+8c) -1)/2
  * iterate c form 1 to n and check the condition it give you solution
  * 
  * 
  * similar for 5,6 make the equation and check condition
  * 
  */


#include<bits/stdc++.h>
using namespace std;
using namespace std;

typedef long long ll;
bool isTriangular(ll x) {
    ll val = 8 * x + 1;
    ll s = sqrt(val);
    if (s * s == val && (s - 1) % 2 == 0) return true;
    return false;
}
bool isPentagonal(ll x) {
    ll val = 24 * x + 1;
    ll s = sqrt(val);
    if (s * s == val && (s + 1) % 6 == 0) return true;
    return false;
}
int main() {
    ll N;
    int a, b;
    cin >> N >> a >> b;
    vector<ll> ans;
    if (a == 3 && b == 5) {
        for (ll n = 1; ; ++n) {
            ll p = n * (3 * n - 1) / 2;
            if (p >= N) break;
            if (isTriangular(p)) ans.push_back(p);
        }
    } 
    else if (a == 5 && b == 6) {
        for (ll n = 1; ; ++n) {
            ll h = n * (2 * n - 1);
            if (h >= N) break;
            if (isPentagonal(h)) ans.push_back(h);
        }
    }
    for (ll res : ans) {
        cout << res << "\n";
    }
    return 0;
}