#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD (lld)(1e9+7)
#define NUM (lld)(5e6+7)

using namespace std;

lld prime[NUM];
lld dp[NUM];

int sieve(){
  
  memset(prime,0,sizeof(prime));
  for(int i=2;i<=NUM;i++)
    if(prime[i]==0)
      for(int j=2*i;j<=NUM;j+=i) if(prime[j]==0)prime[j] = i;
  
}

int main(){
  faster
  lld t,l,r;
  cin>>t>>l>>r;
  sieve();
  dp[1] = 0;
  for(lld i=2;i<=NUM;i++){
    if(prime[i]==0) dp[i] = ((i*(i-1))/2)%MOD;
    else dp[i] = ((i/prime[i]*(prime[i]*(prime[i]-1))/2)%MOD+ dp[i/prime[i]]%MOD)%MOD;
  }  
  
  
  lld ans = 0;
  lld x = 1;
  for(lld i=l;i<=r;i++){
    ans = (ans+(x*dp[i])%MOD)%MOD;
    x = (x*t)%MOD;
  }
  cout<<ans<<endl;
  
}
