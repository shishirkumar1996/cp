#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

int main(){

  string input;
  cin>>input;

  int n= input.size();
  
  int dp[n][n];
  for(int i= 0;i<n;i++) for(int j =0;j<n;j++) dp[i][j] = 0;
  
  vp process;
  
  for(int l = 0;l<n;l++){
    for(int i = 0;i+l<n;i++){
      if(l==0) dp[i][i] = 1;
      else if(l==1 && input[i] == input[i+1]) dp[i][i+1] = 1;
      else if(input[i] == input[i+l] && dp[i+1][i+l-1]==1) dp[i][i+l]=1;
      
      if(dp[i][i+l] == 1){
        process.push_back(make_pair(i,-1));
        process.push_back(make_pair(i+l,1));
      }
    }
  }
  sort(process.begin(),process.end());
//  for(int i =0;i<process.size();i++)cout<<process[i].first<<" "<<process[i].second<<endl;
  lld closed =0;
  lld ans = 0;
  for(int i = 0;i<process.size();i++){
    if(process[i].second == -1) ans+=closed;
    else closed++;
  }
  cout<<ans<<endl;
}
