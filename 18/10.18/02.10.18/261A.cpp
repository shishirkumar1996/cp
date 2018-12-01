#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define fr(i,a,b) for(int i=a;i<b;i++)
#define br(i,a,b) for(int i=(b-1);i>=a;i--)
#define fer(i,a,b) for(int i=a;i<=b;i++)
#define ber(i,a,b) for(int i=b;i>=a;i--)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = "; fr(_,0,n) cerr << a[_]<<' ';cerr<<'\n';}
#define TM

using namespace std;

int main(){

  int m,n;
  cin>>m;
  vi disc(m);
  for(int i=0;i<m;i++)cin>>disc[i];
  cin>>n;
  vi cost(n);
  for(int i=0;i<n;i++)cin>>cost[i];
  sort(disc.begin(),disc.end());
  sort(cost.begin(),cost.end());

  lld ans = 0;
  int i=n-1;
  while(i>=0){
    fer(j,max(0ll,i-disc[0]+1),i)ans+=cost[j];
    i -= disc[0]+2;
  }
  
  cout<<ans<<endl;
  #ifdef TM
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	#endif

}
