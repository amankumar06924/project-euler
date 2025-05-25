#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mx = 1e5;
vector<ll> cntDiv(mx + 1);
void solve()
{

    ll n;
    cin >> n;

    for (ll i = 1; i <= mx; i++)
    {
        ll div;
        if (i % 2 == 0)
        {
            div = cntDiv[i / 2] * cntDiv[i + 1];
        }
        else
        {
            div = cntDiv[i] * cntDiv[(i + 1) / 2];
        }
        if (div > n)
        {
            cout << (i * (i + 1)) / 2 << "\n";
            return;
        }
    }
}

int main()
{

    for (ll i = 1; i <= mx; i++)
    {
        for (ll j = i; j <= mx; j += i)
        {
            cntDiv[j]++;
        }
    }

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}