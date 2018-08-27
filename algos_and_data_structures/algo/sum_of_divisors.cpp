#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define NUM 1007
#define MOD (lld)(1e9+7)

using namespace std;

int prime[NUM];
lld sum_div[NUM];

lld power(lld x,lld y){
  lld res = 1;
  while(y>0){
    if(y & 1) res = (res*x)%MOD;
    y = (y>>1)%MOD;
    x = (x*x)%MOD;
  }
  return res;
}

void sieve(){

  for(int i=0;i<NUM;i++)prime[i] = i;
  
  for(int i=2;i<NUM;i++){ if(prime[i] != i)continue;
    for(int j=2*i;j<NUM;j+=i) prime[j] = i;
  }
}

void calc(){
  
  sum_div[1] = 1;
  for(int i=2;i<NUM;i++){
    lld temp = i;
    map< int,int > process;
    while(temp>1){ process[prime[temp]]++; temp = temp/prime[temp]; }
    map< int,int >::iterator it;
    sum_div[i]  = 1;
    for(it = process.begin();it!=process.end();it++){
      lld pw = 1;
      lld sum = 0;
      for(int j = it->second+1;j>=1;j--){ 
        sum = (sum+pw)%MOD;pw = (pw*(it->first))%MOD;
      }
      sum_div[i] = (sum_div[i]*sum)%MOD;
    }
  }
}

int main(){
  sieve();
  calc();
  for(int i=1;i<NUM;i++)cout<<sum_div[i]<<" ";
  cout<<endl;
}
