#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vs vector< string >
#define MAXM (lld)(1e9+7)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  
  faster
  int n,m;
  cin>>n>>m;
  
  lld minm[n][m];
  for(int i=0;i<n;i++)for(int j=0;j<m;j++) minm[i][j]= MAXM;
  
  vs input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  for(int i=0;i<n;i++){
    lld last = -1;
    for(int j=0;j<2*m;j++){
      if(input[i][j%m]=='1'){ last = j; minm[i][j%m] = 0;}
      else if(last != -1)
        minm[i][j%m] = min(minm[i][j%m],j-last);
    }
    last = -1;
    for(int j=2*m-1;j>=0;j--){
      if(input[i][j%m]=='1'){ last = j; minm[i][j%m] = 0;}
      else if(last != -1) minm[i][j%m] = min(minm[i][j%m],last-j); 
    }
  }
  
  lld ans = MAXM;
  for(int j=0;j<m;j++){
    lld temp = 0;
    for(int i=0;i<n;i++) temp += minm[i][j];
    ans = min(ans,temp);
  }
  if(ans==MAXM) cout<<-1<<endl;
  else cout<<ans<<endl;
}
