#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  faster
  lld n,m;
  cin>>n>>m;
  if(n==1){cout<<1<<" "<<1<<'\n';return 0;}
  else if(m==0){cout<<n<<" "<<n<<'\n';return 0;}
  lld minm = max(0ll,n-2*m);
  lld index = 2;
  while((index*(index-1))/2<m)index++;
  lld maxm = n-index;
  cout<<minm<<" "<<maxm<<endl;
}
