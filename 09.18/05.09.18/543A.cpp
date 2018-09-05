#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;


lld dp[501][501];

int main(){

  int n,m,b; lld mod;
  cin>>n>>m>>b>>mod;
  vi input(n+1);
  for(int i=1;i<=n;i++)cin>>input[i];
  
  for(int i=0;i<=500;i++)for(int j=0;j<=500;j++) dp[i][j] = 0;
  
  for(int i=0;i<=n;i++)dp[0][0] = 1;
  
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      for(int k=0;k<=b;k++){
        lld x = 0,y=0;
        if(i-1>=0)x = dp[j][k];
        if(j-1>=0 && k-input[i]>=0) y = dp[j-1][k-input[i]];
        dp[j][k] = (x+y)%mod;
      }
    }
  }
  lld ans = 0;
  for(int i=0;i<=b;i++)ans = (ans+dp[m][i])%mod;
  cout<<ans<<endl;
}
