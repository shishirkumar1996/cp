#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;


int main(){


  int w,b;
  cin>>w>>b;
  
  double dp[w+1][b+1];
  
  for(int i = 0;i<=w;i++)for(int j = 0;j<=b;j++) dp[i][j] = 0;
  
  for(int i = 1;i<=w;i++){
    for(int j =0;j<=b;j++){
      dp[i][j] = 1.0*i/(i+j);
      if(j>=3) dp[i][j] += 1.0*j/(i+j)*1.0*(j-1)/(i+j-1)*(1.0*(j-2)/(i+j-2)*dp[i][j-3]+1.0*i/(i+j-2)*dp[i-1][j-2]);
      else if(j>=2)
      dp[i][j] += 1.0*j/(i+j)*1.0*(j-1)/(i+j-1)*(1.0*i/(i+j-2)*dp[i-1][j-2]);
    
//      cout<<dp[i][j]<<" ";
    }
  }
  cout<<setprecision(9)<<dp[w][b]<<endl;


}
