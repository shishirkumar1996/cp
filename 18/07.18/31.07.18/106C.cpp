#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);

using namespace std;

int main(){
  
  faster
  int n,m;
  cin>>n>>m;
  
  lld a[m+1],b[m+1],c[m+1],d[m+1];
  
  cin>>c[0]>>d[0];
  for(int i=1;i<=m;i++)cin>>a[i]>>b[i]>>c[i]>>d[i];
  
  lld dp[n+1][m+1];
  for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)dp[i][j] = 0;
  
  lld ans = 0;
  for(int j=0;j<=m;j++){
    for(int i=1;i<=n;i++){
      if(j==0){
        for(int k=1;k<=i/c[j];k++)
          dp[i][j] = max(dp[i][j],k*d[j]);
      } else {
        dp[i][j] = dp[i][j-1];
        for(int k=1;k<=a[j]/b[j] && k<= i/c[j];k++)
          dp[i][j] = max(dp[i][j],dp[i-k*c[j]][j-1]+k*d[j]);
      }
    }
  }
  
  for(int i = 0;i<=n;i++) ans =max(ans,dp[i][m]);
  cout<<ans<<endl;
}
