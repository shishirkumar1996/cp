#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD (lld)(998244353)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  
  int n,m;
  string a,b;
  cin>>n>>m>>a>>b;
  
  reverse(a.begin(),a.end());
  lld num[max(n,m)];
  lld y = 1;
  for(int i=0;i<max(n,m);i++){
    if(i>=n){ num[i] = num[i-1]; continue; }
    num[i] = y*((a[i]=='1')?1:0);
    if(i>0) num[i] += num[i-1];
    num[i] = num[i]%MOD;
    y = (y*2)%MOD;
  }
  lld ans = 0;
  reverse(b.begin(),b.end());
  for(int i=0;i<m;i++) if(b[i]=='1') ans = (ans+num[i])%MOD;
  cout<<ans<<'\n';

}
