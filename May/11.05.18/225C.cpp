#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vc vector< char >
#define MAXM (lld)(1e9+7)

using namespace std;

char input[1001][1001];
int n,m,x,y;


int main(){
  cin>>n>>m>>x>>y;
  
  for(int i = 1;i<=n;i++)
    for(int j = 1;j<=m;j++) cin>>input[i][j];
  

  lld white_sum[m+1];
  
  for(int j = 1;j<=m;j++){
    int sum = 0;
    for(int i = 1;i<=n;i++) if(input[i][j] == '.') sum++;
    white_sum[j] = sum;
  }
  lld dp[2][m+1];
  for(int i = 0;i<2;i++)
    for(int j =  0;j<=m;j++)
     dp[i][j] = MAXM;
     
  dp[1][0] = dp[0][0] = 0;
  
  for(int j = 1;j<=m;j++){
    
    int wh_sum = 0,bl_sum = 0;
    for(int i = 0;i<x-1 && j-i>0;i++)
      wh_sum += white_sum[j-i], bl_sum += (n-white_sum[j-i]);
    for(int i = x-1;i<=y-1 && j-i>0;i++){
      wh_sum += white_sum[j-i],bl_sum += (n-white_sum[j-i]);
      dp[0][j] = min(dp[0][j],dp[1][j-i-1]+wh_sum);
      dp[1][j] = min(dp[1][j],dp[0][j-i-1]+bl_sum);
//      cout<<j<<" "<<dp[0][j]<<" "<<dp[1][j]<<endl;
    }   
  }
  cout<<min(dp[0][m],dp[1][m])<<endl;  
  
}
