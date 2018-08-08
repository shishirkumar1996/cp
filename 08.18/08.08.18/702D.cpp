#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  lld d,k,a,b,t;
  cin>>d>>k>>a>>b>>t;
  
  lld ans = 0;
  
  lld minm = min(d,k);
  ans += minm*a;
  d -= minm;
  
  if(d%k>0){
    lld y = d%k;
    if(t+a*y<b*y) ans = ans+t+a*y; else ans += b*y;
    d -= y;
  }
  
  lld refill = d/k;
  if(a*k+t<b*k) ans += refill*(a*k+t); else ans += (b*k)*refill;
  cout<<ans<<endl;

}
