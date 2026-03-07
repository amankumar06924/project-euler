/**
 * idea is simple first check the given number is palindrome or not then check after converting to basek it is palindrome or not
 * why i converting into string?
 * because when we convert num to string , in string it store in form of digits, it help me to check easily num is palindrom or not 
 */

#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s){
    int n = s.size();
    for(int i=0;i<n/2;i++)
        if(s[i] != s[n-1-i])
            return false;
    return true;
}
string ntok(int n, int k){
    string s = "";
    while(n)
    {
        s += (n % k) + '0';
        n /= k;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    int N, K;
    cin >> N >> K;
    long long sum = 0;
    for(int i = 1; i < N; i++)
    {
        string base10 = to_string(i);
        if(palindrome(base10))
        {
            string baseK = ntok(i, K);
            if(palindrome(baseK))
                sum += i;
        }
    }
    cout << sum << endl;

    return 0;
}