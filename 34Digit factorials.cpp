#include<bits/stdc++.h>
using namespace std;

vector<int> fac(10,1);

void facst(){
    for (int i = 1; i <= 9; i++){
        long long ft = 1;
        for (int j = 1; j <= i; j++){
            ft *= j;
        }
        fac[i] = ft;
    }
}

long long stdig(long long n){
    long long original = n;
    long long sum = 0;

    while (n){
        int r = n % 10;
        n /= 10;
        sum += fac[r];
    }

    if(sum % original == 0){
        return original;
    }
    else{
        return 0;
    }
}

int main(){

    facst();

    int N;
    cin >> N;

    long long ans = 0;

    for (int n = 10; n < N; n++){
        ans += stdig(n);
    }

    cout << ans << endl;

    return 0;
}