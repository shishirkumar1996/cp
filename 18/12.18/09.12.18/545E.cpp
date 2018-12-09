#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld,lld >
#define ppr pair< pr, lld >
#define vppr vector< ppr >
#define vvppr vector< vppr >
#define MAXM (lld)(1e16+7)

using namespace std;

int main(){

  int n,m;
  cin>>n>>m;
  int start;
  vvppr graph(n+1);
  for(int i=1;i<=m;i++){
    lld u,v,w;
    cin>>u>>v>>w;
    graph[u].push_back(make_pair(make_pair(v,w),i));
    graph[v].push_back(make_pair(make_pair(u,w),i));
  }
  cin>>start;
  int ans[n+1];
  lld sol = 0;
  lld dist[n+1],temp[n+1];
  for(int i=1;i<=n;i++)dist[i] = temp[i] = MAXM;
  dist[start] = 0;
  
  priority_queue< pr > process;
  process.push(make_pair(-dist[start],start));
  while(process.size()){
    pr top = process.top();
    process.pop();
    int v = top.second;
    lld x = -top.first;
    for(int i=0;i<graph[v].size();i++){
      int child = graph[v][i].first.first;
      int num = graph[v][i].second;
      lld y = graph[v][i].first.second;
      if(dist[child]>=dist[v]+y && temp[child]>y){
        dist[child] = dist[v]+y;
        temp[child] = y;
        process.push(make_pair(-dist[child],child));
        ans[child] = num;
      }
    }
  }
  for(int i=1;i<=n;i++)if(i != start) sol += temp[i];
  cout<<sol<<'\n';
  for(int i=1;i<=n;i++)
    if(i != start)cout<<ans[i]<<' ';
  cout<<'\n';
}
