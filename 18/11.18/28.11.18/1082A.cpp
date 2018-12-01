#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": "; for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }
#define MAXM (lld)(1e15)

using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    lld n,x,y,d;
    cin>>n>>x>>y>>d;
    lld ans = MAXM;
    if(abs(y-x)%d==0) ans = min(ans,abs(y-x)/d);
    if(abs(1-y)%d==0) ans = min(ans,abs(1-y)/d+(abs(1-x)+d-1)/d);
    if(abs(y-n)%d==0) ans = min(ans,abs(y-n)/d+(abs(n-x)+d-1)/d);
    if(ans==MAXM)cout<<-1<<'\n';
    else cout<<ans<<'\n';
  }
}
