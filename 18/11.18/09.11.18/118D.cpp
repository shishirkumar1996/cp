#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MOD (lld)(1e8)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

int main(){
  
  lld n1,n2,k1,k2;
  cin>>n1>>n2>>k1>>k2;

  lld dp[n1+1][n2+1][2];
  
  for(int i=0;i<=n1;i++){
    for(int j=0;j<=n2;j++){
      if(i==0 && j==0){ dp[i][j][0] = dp[i][j][1] = 1;continue; } 
      dp[i][j][0] = dp[i][j][1] = 0;
      for(int l=max(0ll,i-k1);l<i;l++)dp[i][j][0] += dp[l][j][1];
      for(int l=max(0ll,j-k2);l<j;l++)dp[i][j][1] += dp[i][l][0];
      dp[i][j][0] %= MOD;
      dp[i][j][1] %= MOD;
    }
  }
  cout<<(dp[n1][n2][0]+dp[n1][n2][1])%MOD<<endl;
}
