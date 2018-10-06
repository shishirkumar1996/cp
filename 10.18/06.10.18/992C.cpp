#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = "; fr(_,0,n) cerr<<a[_]<<' ';cerr<<'\n';}
#define TM

using namespace std;

lld power(lld x,lld y){
  lld res = 1;
  x = x%MOD;
  while(y>0){
    if( y&1) res = (res*x)%MOD;
    y = y>>1;
    x = (x*x)%MOD;
  }
  return res;
}


int main(){

  lld x,k;
  cin>>x>>k;
  
  if(x==0){cout<<0<<endl;return 0;}
  lld p = power(2,k);
  lld output = (2ll*x)%MOD;
  output = (output*p)%MOD;
  output  = (output-power(2,k)+1)%MOD;
  
  if(output<0)output += MOD;
  cout<<output<<endl;
  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif

}
