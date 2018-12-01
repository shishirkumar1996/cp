#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld,lld >
#define ppr pair< pr, lld >
#define vp vector< ppr >
#define vvp vector< vp >
#define MAXM (lld)(1e15+7)

using namespace std;

int main(){
  
  int n,m,k;
  cin>>n>>m>>k;
  vvp input(n);
  for(int i=1;i<=m;i++){
    lld x,y,w;
    cin>>x>>y>>w;
    x--,y--;
    input[x].push_back(make_pair(make_pair(y,w),i));
    input[y].push_back(make_pair(make_pair(x,w),i));
  }
  lld dist[n];
  for(int i=0;i<n;i++)dist[i] = MAXM;
  dist[0] = 0;
  priority_queue< ppr > process;
  process.push(make_pair(make_pair(-dist[0],0),-1));
  
  vector< int > output;
  bool processed[n];
  processed[0] = true;
  while(process.size()){
    ppr top = process.top();
    process.pop();
    int v = top.first.second;
    int e = top.second;
    if(!processed[v])output.push_back(e);
    processed[v] = true;
    for(int i=0;i<input[v].size();i++){
      int child = input[v][i].first.first;
      lld w = input[v][i].first.second;  
      int edge = input[v][i].second;
      if(-dist[v]+w>=dist[child]) continue;
      dist[child] = -dist[v]+w;
      process.push(make_pair(make_pair(-dist[child],child),edge));
    }
  }
  int ans = min(k,(int)output.size());
  cout<<ans<<'\n';
  for(int i=0;i<ans;i++)cout<<output[i]<<" ";cout<<'\n'; 
}
