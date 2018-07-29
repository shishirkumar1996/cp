#include<bits/stdc++.h>
#define lld long long int

using namespace std;

int mobius(int n){
  int p= 0;
  if(n%2==0){
    n = n/2;p++;
    if(n%2==0)return 0;
  }
  for(int i=3;i<=sqrt(n);i+=2){
    if(n%i==0){
      n=n/i;p++;
      if(n%i==0)return 0;
    }
  }
  return (p%2==0)?-1:1;
}

int main(){
  cout<<mobius(17)<<" "<<mobius(25)<<endl;
}
