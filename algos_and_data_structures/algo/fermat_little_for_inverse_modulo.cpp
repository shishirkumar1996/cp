#include <bits/stdc++.h>
#define MOD (lld)(1e9+7)
using namespace std;
 
lld power(lld x,lld y);
 
void modInverse(lld a, lld m){  // Assumption: m is prime
    if (__gcd(a, m) != 1) cout << "Inverse doesn't exist";
    else cout << "Modular multiplicative inverse is "<< power(a, m - 2, m)<<endl;    
}
 
lld power(lld x,lld y){
  if (y == 0) return 1;
  lld p = power(x, y / 2) % MOD;
  p = (p * p) % MOD;
  return (y % 2 == 0) ? p : (x * p) % MOD;
}
 
int main(){
  lld a = 3, m = 11;
  modInverse(a, m);
  return 0;
}
