#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(1e15+7)

using namespace std;


int main(){

  faster
  int n;
  cin>>n;
  lld s[n],c[n];
  
  for(int i = 0;i<n;i++) cin>>s[i];
  for(int i = 0;i<n;i++) cin>>c[i];
  
  lld dp1[n][3],dp2[n][3];
  for(int i = 0;i<n;i++) for(int j = 0;j<3;j++) dp1[i][j] = dp2[i][j] = MAXM;
  
  for(int i = 0;i<n;i++){
    for(int j = 0;j<3;j++){
      if(j== 0){dp1[i][j] = c[i];continue;}
      for(int k = 0;k<i;k++)
        if(s[i] > s[k]) dp1[i][j] = min(dp1[i][j],dp1[k][j-1]+c[i]);
    }
  }
  
/*  for(int i = n-1;i>=0;i--){
    for(int j= 0;j<3;j++){
      if(j==0){dp2[i][j] = c[i];continue;}
      for(int k = n-1;k>i;k--)
        if(s[i] >s[k]) dp2[i][j] = min(dp2[i][j],dp2[k][j-1]+c[i]);
    }
  }
  
*/
  lld ans = MAXM;
  for(int i = 0;i<n;i++) ans = min(ans,dp1[i][2]);
  
  if(ans==MAXM)cout<<-1<<endl;
  else cout<<ans<<endl;

}
