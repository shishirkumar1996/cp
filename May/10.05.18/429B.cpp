#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
#define vii vector< vi >

using namespace std;

int main(){

  faster
  int n,m;
  cin>>n>>m;
  lld input[n+2][m+2],dp1[n+2][m+2],dp2[n+2][m+2],dp3[n+2][m+2],dp4[n+2][m+2];
  
  memset(input,0,sizeof(input));
  memset(dp1,0,sizeof(dp1));
  memset(dp2,0,sizeof(dp2));
  memset(dp3,0,sizeof(dp3));
  memset(dp4,0,sizeof(dp4));
  
  for(int i =1;i<=n;i++)
    for(int j = 1;j<=m;j++)
      cin>>input[i][j];
      
  for(int i = 1;i<=n;i++)
    for(int j = 1;j<= m;j++)
      dp1[i][j] = input[i][j]+max(dp1[i-1][j],dp1[i][j-1]);
      
  for(int i=n;i>=1;i--)
    for(int j=m;j>=1;j--)
      dp2[i][j] = input[i][j] + max(dp2[i+1][j],dp2[i][j+1]);

  for(int i= n;i>=1;i--)
    for(int j = 1;j<=m;j++)
      dp3[i][j] = input[i][j]+max(dp3[i+1][j],dp3[i][j-1]);
  
  for(int i= 1;i<=n;i++)
    for(int j = m;j>=0;j--)
      dp4[i][j] = input[i][j]+max(dp4[i-1][j],dp4[i][j+1]);
  
  lld ans = 0;
  for(int i = 2;i<n;i++)
    for(int j = 2;j<m;j++)
      ans = max(ans,max(dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1],dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j]));

  cout<<ans<<endl;

}
