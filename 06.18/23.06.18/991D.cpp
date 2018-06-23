#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);


using namespace std;

//  0 0  1 * *   2   *  3 * *  4 *
//    0      *     * *    *      * *

int main(){

  string input[2];
  cin>>input[0]>>input[1];
  
  int n = input[0].size();
  lld dp[n][5];
  for(int i= 0;i<n;i++)for(int j = 0;j<5;j++) dp[i][j] = 0;
  
  for(int i = 1;i<n;i++){
    for(int j = 0;j<5;j++) dp[i][0] = max(dp[i][0],dp[i-1][j]);
    if(input[0][i] == '0' && input[1][i] == '0'){
      if(input[0][i-1] == '0')
        dp[i][1] = max(dp[i-1][4]+1,dp[i-1][0]+1);
      if(input[1][i-1] == '0')
        dp[i][2] = max(dp[i-1][3]+1,dp[i-1][0]+1);
    }
    if(input[0][i-1] == '0' && input[1][i-1] == '0'){
      if(input[0][i]=='0') dp[i][3] = max(dp[i-1][0]+1,dp[i][3]);
      if(input[1][i] == '0') dp[i][4] =  max(dp[i-1][0]+1,dp[i][4]);
    }
//    cout<<dp[i][3]<<" "<<i<<endl;
  }
  lld maxm = 0;
  for(int i = 0;i<5;i++) maxm = max(maxm,dp[n-1][i]);
  cout<<maxm<<endl;

}
