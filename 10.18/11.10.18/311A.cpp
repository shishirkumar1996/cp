#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';}
#define TM

using namespace std;

int main(){

  lld n,k;
  cin>>n>>k;
  if((n*(n-1))/2<=k){ cout<<"no solution\n";return 0; }
  
  for(int i=0;i<n;i++)cout<<0<<" "<<i<<'\n';

  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif

}
