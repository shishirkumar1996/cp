#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define MAXM (lld)(1e9+7)

using namespace std;

int main(){


  lld dp[31][31][901];
  
  for(int i=0;i<=30;i++)for(int j=0;j<=30;j++)for(int k=0;k<=900;k++)
    dp[i][j][k] = MAXM;

  for(int i=0;i<=30;i++)for(int j=0;j<=30;j++)dp[i][j][0] = 0;

  int count = 0;  
  for(int i=1;i<=30;i++)
    for(int j=1;j<=30;j++){
      for(int k=1;k<=min(i*j,50);k++){
        if(i*j==k){dp[i][j][k] = 0;continue;}
        for(int l=1;l<=i-1;l++)
          for(int m=0;m<=k;m++)dp[i][j][k] = min(dp[i][j][k],j*j+dp[l][j][m]+dp[i-l][j][k-m]);
        for(int l=1;l<=j-1;l++)for(int m=0;m<=k;m++)
          dp[i][j][k] = min(dp[i][j][k],i*i+dp[i][l][m]+dp[i][j-l][k-m]);
      }
    }
  
  int q;
  cin>>q;
  for(int i=1;i<=q;i++){
    int n,m,k;
    cin>>n>>m>>k;
    cout<<dp[n][m][k]<<endl;
  }
}
