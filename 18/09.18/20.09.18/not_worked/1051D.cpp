#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define MOD (lld)(998244353)

using namespace std;

int main(){

  int n,k;
  cin>>n>>k;
  
  int ans[n+1][k+1][4];
  for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)for(int l=0;l<4;l++)
    ans[i][j][l] = 0;
    
  ans[1][1][0] = ans[1][1][3] = 1;
  ans[1][2][1] = ans[1][2][2] = 1;
  for(int i=2;i<=n;i++){
    for(int j=1;j<=2*i;j++){
      ans[i][j][0] = (ans[i-1][j][0]+(j>1?ans[i-1][j-1][1]+ans[i-1][j-1][2]+ans[i-1][j-1][3]:0))%MOD;
      ans[i][j][1] = ((j>1?ans[i-1][j-1][0]+ans[i-1][j-1][3]:0)+ans[i-1][j][1]+(j>2?ans[i-1][j-2][2]:0))%MOD;
      ans[i][j][2] = ((j>1?ans[i-1][j-1][0]+ans[i-1][j-1][3]:0)+(j>2?ans[i-1][j-2][1]:0)+ans[i-1][j][2])%MOD;
      ans[i][j][3]  = ((j>1?ans[i-1][j-1][1]+ans[i-1][j-1][2]+ans[i-1][j-1][0]:0)+ans[i-1][j][3])%MOD;
    }
  }
  cout<<ans[2][2][0]<<" "<<ans[2][2][1]<<" "<<ans[2][2][2]<<" "<<ans[2][2][3]<<endl;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=2*i;j++)cout<<(ans[i][j][0]+ans[i][j][1]+ans[i][j][2]+ans[i][j][3])<<" ";
    cout<<endl;
  }
  lld output = (ans[n][k][0]+ans[n][k][1]+ans[n][k][2]+ans[n][k][3])%MOD;
  cout<<output<<endl;
}
