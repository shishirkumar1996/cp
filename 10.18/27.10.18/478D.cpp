#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

lld dp[2][200007];

using namespace std;

int main(){

  faster
  lld r,g;
  cin>>r>>g;
  
  lld index = 0;
  while(((index+1)*(index+2))/2<=r+g)index++;

  for(int i=0;i<2;i++)for(int j=0;j<=r;j++) dp[i][j] = 0;
  
  dp[0][0] = 1;
  for(int i=1;i<=index;i++){
    for(int j=0;j<=r;j++){
      if(j-i>=0) dp[1][j] += dp[0][j-i];
      dp[1][j] += dp[0][j];
      dp[1][j] = dp[1][j]%MOD;
    }
    for(int j=0;j<=r;j++){ dp[0][j] = dp[1][j]; dp[1][j] = 0;}
  }
    
  lld ans = 0;
  for(int i=0;i<=r;i++){
    if(i+g<((index*(index+1))/2))continue;
    ans  = (ans+dp[0][i])%MOD;
  }
  cout<<ans<<'\n';
}
