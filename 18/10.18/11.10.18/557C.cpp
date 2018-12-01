#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';}
#define MAXM (lld)(1e9+7)
#define TM

using namespace std;

int main(){

  int n;
  cin>>n;
  multiset< lld >process;
  map< lld,vi > temp;
  lld sum = 0;
  for(int i=0;i<n;i++){
    lld a,b;
    cin>>a>>b;
    process.insert(-b);
    temp[-a].push_back(b);
    sum += a;
  }
  
  lld min = MAXM;
  map< lld,vi >::iterator it;
  for(it = temp.begin();it != temp.end();it++){
    vi x = temp->second;
    for(int i=0;i<x.size();i++){ process.erase(process.find(-x[i]));sum
    int index = 0;
    multiset< lld >
  }
  
  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif

}
