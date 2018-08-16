#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio;cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  faster
  string input;
  cin>>input;
  
  int n = input.size();
  vi output(n+1,0);
  
  int dp[n][n];
  
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)dp[i][j] = 0;
  
  for(int l=1;l<=n;l++){
    for(int i=0;i<n-l+1;i++){
      int j=i+l-1;
      if(l==1){dp[i][j] = 1;output[1]++;}
      else if(l==2){
        if(input[i]==input[j]){ dp[i][j] = 2;output[2]++; }
      } else if(dp[i+1][j-1]&&(input[i]==input[j])){ dp[i][j] = dp[i][i+l/2-1]+1;output[dp[i][j]]++;}
//      cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    }
  }
  for(int i=n-1;i>=1;i--)output[i] += output[i+1];
  
  for(int i=1;i<=n;i++)cout<<output[i]<<" ";
  cout<<endl;
}
