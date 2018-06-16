#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  vi input(n+1);
  for(int i = 1;i<=n;i++) cin>>input[i];
  
  lld dp[n+1][2];
  
  dp[0][0] = dp[0][1] = 0;
  lld odd_max,even_max;
  even_max = 0;
  odd_max = INT_MIN;
  
  for(int i = 1;i<=n;i++){
    dp[i][0] = dp[i-1][0],dp[i][1]=dp[i-1][1];
    if(input[i]%2==0){
      if(dp[i-1][1] != 0)
        odd_max = max(odd_max,dp[i-1][1]+input[i]),dp[i][1]= odd_max;
      even_max = max(even_max,dp[i-1][0]+input[i]),dp[i][0] = even_max;
    }
    else{
      if(dp[i-1][1] != 0)
        even_max = max(even_max,dp[i-1][1]+input[i]),dp[i][0] = even_max;
      odd_max = max(odd_max,dp[i-1][0]+input[i]),dp[i][1] = odd_max;
    }
//    cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<i<<endl;
  }
    
  cout<<odd_max<<endl;
}
