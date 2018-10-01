#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){

  int n;
  cin>>n;
  
  vi input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  int dp[n+1][n+1];
  for(int l=1;l<=n;l++){
    for(int i=0;i<n-l+1;i++){
      if(l==1)dp[i][l] = 1;
      else if(l==2){
        if(input[i]==input[i+1])dp[i][l] = 1;
        else dp[i][l] = 2;
      } else{
        dp[i][l] = INT_MAX;
        if(input[i]==input[i+l-1])dp[i][l] = dp[i+1][l-2];
        for(int j=1;j<=l-1;j++){
          dp[i][l] = min(dp[i][l],dp[i][j]+dp[i+j][l-j]);
        }
      }
    }
  }
  cout<<dp[0][n]<<endl;
}
