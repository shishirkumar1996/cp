#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = "; fr(_,0,n) cerr<<a[_]<<' ';cerr<<'\n';}
#define pr pair< int,int >

using namespace std;


int main(){
  
  faster
  int n;
  cin>>n;
  
  vector< pr > output;
  for(int i=2;i<n;i++){
    if(((n+i-1)%(2*i-1)==0)||(n%(2*i-1)==0))output.push_back(make_pair(i,i-1));
  }
  for(int i=2;i<n;i++){
    if(n%i!=0)continue;
    output.push_back(make_pair(i,i));
  }
  sort(output.begin(),output.end());
  
  cout<<n<<":\n";
  for(int i=0;i<output.size();i++)cout<<output[i].first<<','<<output[i].second<<'\n';
  
  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif

}

//xn+(x-1)(n-1) = z
//xn + (x-1)n - (x-1) = z
//n(2x-1) = z+x-1

//xn+(x-1)n = z
//n(2x-1) = z

