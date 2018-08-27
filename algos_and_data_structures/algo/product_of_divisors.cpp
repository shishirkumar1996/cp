#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define NUM 1007
#define MOD (lld)(1e9+7)

using namespace std;

int prime[NUM];
lld prod_div[NUM];

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
  
  prod_div[1] = 1;
  for(int i=2;i<NUM;i++){
    lld temp = i;
    map< int,int > process;
    while(temp>1){ process[prime[temp]]++; temp = temp/prime[temp]; }
    map< int,int >::iterator it;
    lld num_factor  = 1;
    for(it = process.begin();it!=process.end();it++)
      num_factor = num_factor*(it->second+1);
    prod_div[i] = power(i,num_factor/2);
    if(num_factor%2==1) prod_div[i] = (prod_div[i]*(lld)sqrt(i))%MOD;
    //this ensures whether number is square or not
  }
}

int main(){
  sieve();
  calc();
  for(int i=1;i<NUM;i++)cout<<prod_div[i]<<" ";
  cout<<endl;
}
