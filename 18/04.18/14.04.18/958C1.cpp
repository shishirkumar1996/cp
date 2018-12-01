#include<bits/stdc++.h>

#define lld long long int
#define vi vector < lld >

using namespace std;

lld calc(int n,lld modulo,vi input){

  lld sum[n];
  
  for(int i =0;i<n;i++)
    sum[i] = (i==0)?input[i]:(sum[i-1]+input[i]);
  
  lld maxm = 0;
  for(int i = 0;i<n-1;i++){
    lld first = sum[i]%modulo;
    lld second = (sum[n-1]-sum[i])%modulo;
    maxm = max(maxm,first+second);
  }  

  return maxm;
}

int main(){
  
  ios::sync_with_stdio(false);
  int n;
  lld modulo;
  vi input;
  cin>>n>>modulo;
  input.resize(n);
  for(int i = 0;i<n;i++)
    cin>>input[i];
    
  cout<<calc(n,modulo,input)<<endl;
}
