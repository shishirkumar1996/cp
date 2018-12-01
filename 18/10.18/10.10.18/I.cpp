#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = "; for(int i=0;i<n;i++)cerr<<a[i]<<' ';cerr<<'\n';}
#define NUM 1000

using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vi input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  int num[n][m+1];
  for(int i=0;i<n;i++)for(int j=0;j<=m;j++)num[i][j] = INT_MIN;
  num[0][0]  = 0;
  for(int i=1;i<n;i++){
    for(int j=0;j<=m;j++){
      if(j==m) num[i][j] = max(num[i-1][j-1],num[i-1][j]);
      else if(j)num[i][j] = num[i-1][j-1];
      else num[i][j] = max(num[i-1][m-1],num[i-1][m])+input[i];
    }
  }
  int ans = 0;
  for(int i=0;i<=m;i++)ans = max(ans,num[n-1][i]);
  cout<<ans<<endl;
//  for(int i=0;i<n;i++){for(int j=0;j<=m;j++)cout<<num[i][j]<<" ";cout<<endl;}
  
  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif

}
