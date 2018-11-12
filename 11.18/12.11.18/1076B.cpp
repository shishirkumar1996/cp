#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define NUM 100007

using namespace std;

bool prime[NUM];

bool sieve(){

  for(int i=2;i<NUM;i++)prime[i] = true;
  
  for(int i=2;i<NUM;i++){
    if(!prime[i])continue;
    for(int j=2*i;j<NUM;j+=i)prime[j] = false;
  }
}

int main(){
  
  sieve();
  lld n;
  cin>>n;
  
  lld index=-1;
  for(int i=2;i<NUM;i++)if(prime[i] && n%i==0){ index = i;break;}
  
  if(index==-1)index = n;
  lld ans;
  if(index==2) ans = n/index;
  else ans = 1+(n-index)/2ll;
  cout<<ans<<endl;
}
