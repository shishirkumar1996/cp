#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = "; fr(_,0,n) cerr<<a[_]<<' ';cerr<<'\n';}
#define TM

using namespace std;

int main(){

  lld n;
  cin>>n;
  
  lld ans = 0;
  lld num = 1;
  while(true){
    if(n%num==0) num *= 3;
    else { ans = n/num+1;break; }
  }
  
  cout<<ans<<endl;
  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif

}
