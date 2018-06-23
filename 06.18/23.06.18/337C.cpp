#include<bits/stdc++.h>
#define lld long long int
#define MOD (lld)(1e9+9)

using namespace std;

int main(){

  lld n,m,k;
  cin>>n>>m>>k;
  
  if(n/k*(k-1)+n%k>=m){cout<<m<<endl;return 0;}
  
  lld diff = m-n/k*(k-1)-n%k;
  lld ans = 1;
  
  lld counter = diff+1;
  lld base = 2;
  while(counter > 0) {
    if( counter %2 != 0) ans = (ans*base)%MOD;
    base = (base*base)%MOD;
    counter = counter/2;
  }
  ans = ((ans-2+MOD)*k)%MOD;
  ans = (ans+m-diff*k)%MOD;
  cout<<ans<<endl;
}
