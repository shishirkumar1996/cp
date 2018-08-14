#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define NUM 605
#define MAXM 1000007

using namespace std;

int dp[NUM][NUM],calc[NUM][NUM],sum[NUM];

int main(){

  faster
  int n,m,l;
  cin>>n>>m>>l;
  
  for(int i=0;i<NUM;i++)for(int j=0;j<NUM;j++) dp[i][j] = calc[i][j] = MAXM;
  
 
  vector< string > input(n);
  for(int i=0;i<n;i++)cin>>input[i];
 
  for(int i=0;i<n;i++){
    sum[i] = 0;
    for(int j=0;j<m;j++)if(input[i][j]=='1')sum[i]++;
    
  }
   
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int num = 0;
      for(int k=j;k<m;k++){
        if(input[i][k]=='1') num++;
        int days= k-j+1;
        int miss = sum[i]-num;
        calc[i][miss] = min(calc[i][miss],days);
      }
    }
    calc[i][sum[i]] = 0;
  }
//  for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<calc[i][j]<<" ";cout<<endl;}
  
  for(int i=0;i<n;i++){
    for(int j=0;j<=l;j++){
      for(int k=0;k<=min(j,l);k++){
        if(i==0) dp[i][j] = min(dp[i][j],calc[i][k]);
        else dp[i][j] = min(dp[i][j],dp[i-1][j-k]+calc[i][k]);
      }
    }
  }
//  for(int i=0;i<n;i++){for(int j=0;j<=l;j++)cout<<dp[i][j]<<" ";cout<<endl;}
  
  cout<<dp[n-1][l]<<endl;
}
