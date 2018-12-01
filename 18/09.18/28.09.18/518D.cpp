#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  int n,t;
  double p;
  cin>>n>>p>>t;
  
  double ans[t+1][n+1];
  for(int i=0;i<=t;i++)for(int j=0;j<=n;j++) ans[i][j] = 0;
  ans[0][0] = 1;
  
  for(int i=1;i<=t;i++)
    for(int j=0;j<=n;j++){
      if(j==0) ans[i][j] = ans[i-1][j]*(1-p);
      else if(j==n) ans[i][j] = ans[i-1][j]+ans[i-1][j-1]*p;
      else ans[i][j] = ans[i-1][j]*(1-p)+ans[i-1][j-1]*p;
    }
  double output = 0;
  for(int i=1;i<=n;i++) output += ans[t][i]*i;
  cout<<setprecision(15)<<output<<endl;
}
