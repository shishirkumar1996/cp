#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define NUM 100007

using namespace std;

vector< int > prime_factors[NUM];

void sieve(){

  int prime[NUM];
  for(int i=0;i<NUM;i++)prime[i] = i;
  
  for(int i=2;i<NUM;i++){
    if(prime[i] != i)continue;
    for(int j=2*i;j<NUM;j+=i)prime[j] = i;
  }  
  
  for(int i=2;i<NUM;i++){
    int temp = i;
    while(temp>1){
      int p = prime[temp];
      prime_factors[i].push_back(p);
      while(temp%p==0)temp = temp/p;  
    }
    sort(prime_factors[i].begin(),prime_factors[i].end());
  }
}

int main(){

  sieve();
  int n;
  cin>>n;
  vi input(n);
  for(int i=0;i<n;i++)cin>>input[i];

  vector< int > x[NUM];
  int length[n];
  for(int i=0;i<n;i++){
    int a = input[i];
    if(i==0) length[i] = 1;
    else{
      int maxm = 0;
      for(int j=0;j<prime_factors[a].size();j++){
        if(!x[prime_factors[a][j]].size())continue;
        int y = x[prime_factors[a][j]].back();
        maxm = max(length[y],maxm);
      }
      length[i] = maxm+1;
    }
    for(int j=0;j<prime_factors[a].size();j++){
      int y = prime_factors[a][j];
      x[y].push_back(i);
    }
  }
  int maxm = 1;
  for(int i=0;i<input.size();i++)maxm =max(maxm,length[i]);
  cout<<maxm<<endl;
}
