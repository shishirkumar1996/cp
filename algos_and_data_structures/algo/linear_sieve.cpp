#include<bits/stdc++.h>
#define NUM 10000007
#define vi vector< int >

using namespace std;

int lp[NUM];
vi pr;

void linear_sieve(int n){
  for(int i=2;i<=n;i++){
    if(lp[i] == 0){ lp[i] = i;pr.push_back(i); }  
    for(int j=0;j<(int)pr.size()&& pr[j]<=lp[i] && i*pr[j]<=n;++j)
      lp[i*pr[j]] = pr[j];
  }
}

int main(){
  int n = 1000;
  linear_sieve(n);
  for(int i=2;i<=n;i++)cout<<lp[i]<<" ";
  cout<<endl;
}
