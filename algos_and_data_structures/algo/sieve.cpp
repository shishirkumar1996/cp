#include<bits/stdc++.h>
#define NUM 100007

using namespace std;



int prime[NUM]; // 0 means a prime number, otherwise the divisor of that number

void sieve(int n){

  memset(prime,0,sizeof(prime));
  
  for(int p=2;p*p<=n;p++)
    if(prime[p]==0) for(int i=p*2;i<=n;i+=p)prime[i] = p;
}

int main(){
  int n=100;
  sieve(n);
  for(int i=2;i<n;i++)cout<<prime[i]<<" ";
  cout<<endl;
}
