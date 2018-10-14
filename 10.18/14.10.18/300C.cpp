#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define pr pair< int,int >
#define vp vector< pr >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": "; for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';
#define MOD (lld)(1e9+7)

using namespace std;

lld power(lld x,lld y);
 

lld modInverse(lld a,lld m){  // Assumption: m is prime
    return power(a, m - 2);    
}
 
lld power(lld x,lld y){
  if (y == 0) return 1;
  lld p = power(x, y / 2) % MOD;
  p = (p * p) %MOD;
  return (y % 2 == 0) ? p : (x * p) % MOD;
}

int main(){

  lld a,b,n;
  cin>>a>>b>>n;
  
  lld fact[n+1];
  
  fact[0] =1;
  for(int i=1;i<=n;i++) fact[i] = (fact[i-1]*i)%MOD;
  
  lld ans = 0;
  for(int i=0;i<=n;i++){
    lld x = a*i+b*(n-i);
    int flag = 1;
    while(x){
      int temp = x%10;
      if(temp != a && temp != b){ flag = 0;break;}
      x = x/10;
    }
    if(!flag)continue;
    ans += (fact[n]*modInverse((fact[i]*fact[n-i])%MOD,MOD))%MOD;
    ans = ans%MOD;
  }
  cout<<ans<<endl;
}
