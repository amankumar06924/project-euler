#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x){
  if (x <= 1)
    return false;
  for (int factor = 2; factor*factor <= x; factor++)
    if (x % factor == 0)
      return false;
  return true;
}

int main(){
int n;
cin >> n;
  unsigned int consecutive = 0;
  int bestA = 0;
  int bestB = 0;
  for (int a = -n; a <= +n; a++)
    for (int b = -n; b <= +n; b++){
      unsigned int length = 0;
      while (isPrime(length * length + a * length + b)) length++;
      if (consecutive < length){
        consecutive = length;
        bestA = a;
        bestB = b;
      }
    }
  cout << bestA << " " << bestB << endl;
  return 0;
}