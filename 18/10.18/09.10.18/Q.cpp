#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = "; fr(_,0,n) cerr<<a[_]<<' ';cerr<<'\n';}

using namespace std;


int main(){
  
  lld n;
  cin>>n;
  lld total_num = (n*(n-1))/2;
  lld mid = (total_num+1)/2;
  
  lld temp = 0;
  lld num = n-1;
  lld ans = 0;
  while(temp<mid){
    ans++;
    temp+= num;
    num--;
  }
  cout<<ans<<endl;

  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif

}
