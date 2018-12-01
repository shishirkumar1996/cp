#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >

using namespace std;

int main(){

  faster
  int n,m;
  cin>>n>>m;
  lld input[n+1][m+1];
  int dp[n+1][m+1], maxm[n+1];

  for(int i=1;i<=n;i++){
    int x = 0;
    for(int j=1;j<=m;j++){
      cin>>input[i][j];
      if(i==1)dp[i][j] = 1;
      else {
        if(input[i][j]>=input[i-1][j]) dp[i][j] = dp[i-1][j]+1;
        else dp[i][j] = 1;
      }
      x = max(x,dp[i][j]);
    }
    maxm[i] = x;
  }

  int k;
  cin>>k;
  for(int i=1;i<=k;i++){
    int l,r;
    cin>>l>>r;
    if(r-maxm[r]+1<=l)cout<<"Yes"<<'\n'; else cout<<"No"<<'\n';
  }
}
