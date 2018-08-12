#include <bits/stdc++.h>
using namespace std;
 
int power(int x, unsigned int y, unsigned int m);
 

void modInverse(int a, int m){  // Assumption: m is prime
    if (__gcd(a, m) != 1) cout << "Inverse doesn't exist";
    else cout << "Modular multiplicative inverse is "<< power(a, m - 2, m)<<endl;    
}
 
int power(int x, unsigned int y, unsigned int m){
  if (y == 0) return 1;
  int p = power(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
 
int main(){
  int a = 3, m = 11;
  modInverse(a, m);
  return 0;
}
