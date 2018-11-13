#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld,lld >
#define vp vector< pr >
#define vi vector< lld >
#define vpp vector< vp >
#define NUM 200007

using namespace std;

vpp graph(NUM);
int p[NUM];
lld dist[NUM];

bool dfs(int v,lld d){
  dist[v] = d;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i].first;
    if(child==p[v])continue;
    dfs(child,d+graph[v][i].second);
  }
}

int main(){

  faster
  int n;
  cin>>n;
  vi input(n+1);
  for(int i=1;i<=n;i++)cin>>input[i];
  
  p[1] = -1;
  for(int i=2;i<=n;i++){
    lld a,b;
    cin>>a>>b;
    p[i] = a;
    graph[a].push_back(make_pair(i,b));
    graph[i].push_back(make_pair(a,b));
  }
  dfs(1,0);
  
  int ans[n+1];
  for(int i=0;i<=n;i++)ans[i] = 0;
  
  for(int i=1;i<=n;i++){
    int temp = i;
    lld val = dist[i]-input[i];
    while(temp != 1){
      int parent = p[temp];
      if(val<=dist[parent])ans[parent]++;
      temp = parent;
    }
  }
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<'\n';
}
