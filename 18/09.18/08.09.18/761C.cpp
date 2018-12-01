#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vs vector< string >
#define MAXM 100007

using namespace std;

int main(){
  
  int n,m;
  cin>>n>>m;
  vs input(n+1);
  for(int i=1;i<=n;i++)cin>>input[i];
  
  int dp[n+1][8];
  for(int i=0;i<=n;i++)for(int j=0;j<8;j++)dp[i][j] = MAXM;
  dp[0][0] = 0;
  
  for(int i=1;i<=n;i++)
    for(int j=0;j<m;j++)
      for(int k=0;k<8;k++){
        int temp;
        if(input[i][j]>='a' && input[i][j]<='z') temp = 1;
        if(input[i][j]>='0' && input[i][j]<='9') temp = 2;
        if(input[i][j] == '#' || input[i][j]=='*' || input[i][j]=='&') temp=4;
        dp[i][k|temp] = min(dp[i][k|temp],min(dp[i-1][k|temp],dp[i-1][k]+min(j,m-j)));
//        cout<<i<<" "<<k<<" "<<" "<<(k|temp)<<" "<<dp[i][k|temp]<<endl;
      }
  
  cout<<dp[n][7]<<endl;
}
