#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int main(){

  faster
  int n,m,k;
  cin>>n>>m>>k;
  
  int temp[n+1][m+1];
  
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>temp[i][j];
    
  int sum[n+1][m+1];
  for(int i=0;i<=m;i++) sum[0][i] = 0;
  
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    sum[i][j] = sum[i-1][j]+(temp[i][j]==1?1:0);
  
  int ans = 0,cut = 0;
  for(int i=1;i<=m;i++){
    int maxm = 0,index=1;
    for(int j=1;j<=n;j++){
      int last = min(j+k-1,n);
      int temp = sum[last][i]-sum[j-1][i];
      int cut = sum[j-1][i];
      if(temp>maxm){maxm = temp;index = j;}
    }
    ans += maxm;
    cut += sum[index-1][i];
  }
  cout<<ans<<" "<<cut<<endl;
}
