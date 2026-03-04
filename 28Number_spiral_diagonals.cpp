/** let me explain how i solve
 * 21  22  23  24  25
   20   7   8   9  10
   19   6   1   2  11
   18   5   4   3  12
   17  16  15  14  13

   if our matrix is 3X3 1,3,5,7
   as you can se the matrix is 5X5
   diagonal sum is = 1,3,5,7,9,13,17,21,25

   1+(3,5,7,9) + (13,17,21,25) + .........m group
   we know AP sum = n/2(2a + (n-1)d) , as you can see our n is 4 and d(common difference) varies. so we can write like this 
   1 + (4a1 + 6d1) + (4a2 + 6d2) + .....
   1 + 4(a1 + a2 + a3 + ...) + 6(d1 + d2 + d3+....)
   as we can see 
   a1 = 3 and d1 = 2;
   a2 = 3^2 + 4 and d2 = 4;
   a3 = 5^2 + 6 and d3 = 6;
 put the value of a1,a2,a3...am and d1,d2,d3...dm
  1 + 4((2+1) + (3^2 + 4) + (5^2 + 6) ......) + 6(2+4+6+8+......)
  1 + 4(1 + 3^2 + 5^2 + 7^2 + ......)  + 10(2+4+6+8+....)

  ************************************************
  * total sum =  1 + 4(m(4m^2-1)/3) + 10(m(m+1)) *
  ************************************************

  how you find m ? its simple
  you can see if 3X3 , m=1;
  5X5 , m=2
  7X7 , m=3
  nXn , m = (n-1)/2

*/

#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        long long n = ((N - 1) / 2) % mod; 
        long long ans = 0;
        long long inv3 = 333333336;
        long long n_sq = (n * n) % mod;
        long long inner = (4 * n_sq - 1 + mod) % mod;
        long long term1 = (n * inner) % mod;
        long long term1_final = (4 * term1) % mod;
        long long part1 = (term1_final * inv3) % mod;
        long long part2 = (10 * ((n * (n + 1)) % mod)) % mod;
        ans = (part1 + part2 + 1) % mod;
        cout << ans << endl;
    }
    return 0;
}