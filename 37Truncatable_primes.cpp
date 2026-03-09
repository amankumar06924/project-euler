/**
 * ok so main problem is how to remove digit form right,
 * lets take a example n = 123456
 * to remove right most digit just modulo with 10^dig like 123456%100000 it give you 23456
 * then 23456%10000 its give you 3456 and its goes so on thats it;
 */

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000000 + 5;
vector<bool> prime(MX, true);
void sieve()
{
    prime[0] = prime[1] = false;

    for (int i = 2; i * i < MX; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < MX; j += i)
                prime[j] = false;
        }
    }
}
bool rtol(int n){
    while (n){
    if (!prime[n]) return false;
        n /= 10;
    }
    return true;
}
bool ltor(int n){
    int pow10 = 1;

    while (pow10 <= n)
        pow10 *= 10;
    pow10 /= 10;
    while (pow10 > 0)
    {
        if (!prime[n]) return false;
        n %= pow10;
        pow10 /= 10;
    }
    return true;
}

int main()
{
    sieve();
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 11; i <= n; i++)
    {
        if (prime[i] && rtol(i) && ltor(i))
            sum += i;
    }

    cout << sum << endl;
}