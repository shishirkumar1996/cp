#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  faster
  int n;
  cin>>n;
  string input;
  cin>>input;
  
  int sum[26][n+1];
  for(int i=0;i<26;i++)sum[i][0] = 0;

  for(int i=0;i<26;i++)for(int j=1;j<=n;j++)
    if(input[j-1]==i+'a')sum[i][j] = sum[i][j-1]+1;
    else sum[i][j]= sum[i][j-1];
  

  int dp[26][n+1];
  for(int i=0;i<26;i++) for(int j=0;j<=n;j++)dp[i][j] = 0;
  
  for(int k=0;k<26;k++)
  for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++){
      int diff = sum[k][j]-sum[k][i-1];
      int x = (j-i+1)-diff;
      dp[k][x] = max(dp[k][x],j-i+1);
    }
    
  for(int i=0;i<26;i++)for(int j=1;j<=n;j++) dp[i][j] = max(dp[i][j],dp[i][j-1]);  
  
  int q;
  cin>>q;
  for(int i=1;i<=q;i++){
    int k;
    char ct;
    cin>>k>>ct;
    cout<<dp[ct-'a'][k]<<'\n';
  }
}
