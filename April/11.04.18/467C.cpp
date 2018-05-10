#include<bits/stdc++.h>

#define lld long long int
#define vi vector < lld >
using namespace std;


lld calc(int n,int m, int k,vi input){

  lld dp[n+1][k+1];  
  for(int i =0;i<=n;i++)
    for(int j = 0;j<=k;j++)
      dp[i][j] = (i<m && j==0)?0:-1;
  
  
  
  for(int i = m;i<=n;i++){
    lld sum = 0;
    for(int l = i-m+1;l<=i;l++)
      sum += input[l-1];
    
    for(int j = 1;j<=k;j++){
      lld last = max(dp[i-m][j-1],(lld)0);
      dp[i][j] = max(dp[i][j],max(dp[i-1][j],last+sum));
//      cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    }
  }

  
  return dp[n][k];
}

int main(){
  int n,m,k;
  cin>>n>>m>>k;
  vi input;
  for(int i =0;i<n;i++){
    lld sum;
    cin>>sum;
    input.push_back(sum);
  }
  cout<<calc(n,m,k,input)<<endl;

}
