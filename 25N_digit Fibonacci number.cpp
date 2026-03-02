#include <bits/stdc++.h>
using namespace std;

long long firstIndexWithDigits(int D)
{
    long double phi = (1 + sqrt(5.0L)) / 2;
    long double log_phi = log10(phi);
    long double log_sqrt5 = log10(sqrt(5.0L));

    long long low = 1, high = 30000;
    long long ans = 0;

    while(low <= high)
    {
        long long mid = (low + high) / 2;

        long long digits =
        floor(mid * log_phi - log_sqrt5) + 1;
        if(digits >= D)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int D;
        cin >> D;
        cout << firstIndexWithDigits(D) <<endl;
    }
}