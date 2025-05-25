#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

bool palindrome(int n){
    string s(to_string(n));
    int l= s.length();
    for(int i=0;i<l/2;i++){
        if(s[i] != s[l-i-1]) return false;
    }
    return true;
}

int find_max(int n){
    int max= 0;
    int produit;
    for(int n1=100;n1<1000;n1++){
        for(int n2=n1;n2<1000;n2++){
            produit=n1*n2;
            if(produit > max && produit < n && palindrome(produit))
               max=produit;
       }
    }
    return max;
}


int main() {
    int T, N;
    cin >> T;
    for(int i=0; i< T; i++){
        cin >> N;
        cout << find_max(N) << endl;
    }   
    return 0;
}