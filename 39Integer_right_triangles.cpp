/**
 * How I solved this problem
 * The main idea of this problem is to count how many right triangles
 * 
 * Euclid's formula:
 * a = m^2 - n^2
 * b = 2mn
 * c = m^2 + n^2

 * The perimeter becomes:
 * p = a + b + c
 * p = 2*m*(m+n)
 
 * Using this formula we generate primitive Pythagorean triples.
 * Conditions required:
 * 1) gcd(m,n) = 1
 * 2) (m-n) must be odd
 *
 * These conditions ensure we generate only primitive triples.
 *
 * Every primitive triangle also has multiples:
 *
 * (3,4,5) -> p = 12
 * (6,8,10) -> p = 24
 * (9,12,15) -> p = 36
 *
 * So once we find a base perimeter p, we increase the count for:
 *
 * p, 2p, 3p, 4p ...
 *
 * We store this in an array:
 *
 * cnt[p] = number of right triangles with perimeter p
 *
 * After computing all counts, we build another array:
 *
 * best[i]
 *
 * best[i] stores the perimeter <= i that has the maximum number
 * of right triangle solutions so far.
 *
 * Finally for every query N, we simply output:
 *
 * best[N]
 *
 * because it already stores the correct answer.
 */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000000;

int main()
{
    vector<int> cnt(MAXN + 1, 0);
    for (int m = 2; 2 * m * m <= MAXN; m++){
        for (int n = 1; n < m; n++){
            if (((m - n) & 1) && __gcd(m, n) == 1){
                int p = 2 * m * (m + n);
                if (p > MAXN)
                    break;
                for (int k = p; k <= MAXN; k += p)
                    cnt[k]++;
            }
        }
    }

    vector<int> best(MAXN + 1);
    int mx = 0, ans = 0;
    for (int i = 0; i <= MAXN; i++)
    {
        if (cnt[i] > mx)
        {
            mx = cnt[i];
            ans = i;
        }
        best[i] = ans;
    }

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << best[n] << endl;
    }
}