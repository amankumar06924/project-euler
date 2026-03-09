/**
 * ok so we are given tn
 *  and tn = n*(n+1)/2
 * so we can write like this n^2 + n - 2*tn = 0;
 * and the root of this equation is alpha = (-1+sqrt(1+8*tn))/2;
 * so the solution is posible only if (1+8n) should be perfect squre thats why i check sqrt(1+8n) == (int)sqrt(1+8n)
 * if its perfect squre then alpha is our solution
 * (ans>>1)=(ans/2) , {right shift of number}
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while (t--)
{
    long long n;
    cin>>n;
    long long sqt = sqrt(1 + 8*n);
    bool flag = true;
    long long ans = 0;
    if(sqrt(1+8*n)==(int)sqrt(1+8*n)){
        ans = sqrt(1 + 8*n)-1;
    }else
    {
        flag = false;
    }
    if(flag){
        cout<<(ans>>1)<<endl;
    }else
    {
        cout<<-1<<endl;
    }
}
return 0;
}