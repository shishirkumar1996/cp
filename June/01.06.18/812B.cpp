#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int main(){
  
  faster
  int n,m;
  cin>>n>>m;
  vii input(n);
  
  int left[n],right[n],num_one[n];
  for(int i = n-1;i>=0;i--){
    left[i] = 0;right[i] = m+1;num_one[i]  = 0;
   for(int j=0;j<m+2;j++) {
    char c;
    cin>>c;
    input[i].push_back(c-'0');
      if(input[i][j])
        left[i] = max(left[i],j),right[i] = min(right[i],j),num_one[i]++;
    }
  }
  
  int dp[2][n];
  for(int i = 0;i<2;i++)for(int j= 0;j<n;j++)dp[i][j] = 100000;
  
  dp[0][0] = left[0];
  for(int i = 1;i<n;i++){
    dp[0][i] = min(left[i]+left[i-1]+dp[0][i-1],left[i]+right[i-1]+dp[1][i-1])+1;
    dp[1][i] = min((m+1-right[i])+(m+1-left[i-1])+dp[0][i-1],(m+1-right[i])+(m+1-right[i-1])+dp[1][i-1])+1;
  }
  for(int i = n-1;i>=0;i--){
    if(num_one[i]){
      cout<<min(dp[0][i],dp[1][i])<<endl;
      return 0;
    }
  }
  cout<<0<<endl;
}
