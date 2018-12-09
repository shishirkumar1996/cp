#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define pr pair< lld,lld >
#define vp vector< pr >
#define vip vector< vp >
#define MAXM (lld)(1e16+7)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": "; for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

int main(){

  faster
  int n,m;
  cin>>n>>m;
  
  vip graph(n+1);
  for(int i=0;i<m;i++){
    lld a,b,c;
    cin>>a>>b>>c;
    graph[a].push_back(make_pair(b,c));
    graph[b].push_back(make_pair(a,c));
  }
  vii process(n+1);
  map< lld,lld > mp[n+1];
  vii diff(n+1);
  for(int i=1;i<=n;i++){
    int k;
    cin>>k;
    for(int j=0;j<k;j++){
      lld x;
      cin>>x;
      process[i].push_back(x);
      diff[i].push_back(x-j);      
    }
    for(int j=0;j<k;j++){
      int index = lower_bound(diff[i].begin(),diff[i].end(),diff[i][j]+1)-diff[i].begin();
      index--;
      mp[i][process[i][j]] = process[i][index]+1;
    }
  }
  lld dist[n+1];
  for(int i=0;i<=n;i++)dist[i] = MAXM;
  dist[1]  = 0;
  priority_queue< pr > temp;
  temp.push(make_pair(-dist[1],1));
  
  while(temp.size()){
    pr top = temp.top();
    temp.pop();
    lld d = -top.first;
    lld v = top.second;
    if(mp[v][d]) d = mp[v][d];
    for(int i=0;i<graph[v].size();i++){
      int child = graph[v][i].first;
      lld x = graph[v][i].second;
      if(d+x<dist[child]){
        dist[child] = d+x;
        temp.push(make_pair(-dist[child],child));
      } 
    }
  }
  if(dist[n] == MAXM) cout<<-1<<'\n';
  else cout<<dist[n]<<'\n';
}
