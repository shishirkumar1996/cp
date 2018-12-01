#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define NUM 1000007

using namespace std;

vii graph(NUM);
int parent[NUM],dist[NUM],longest[NUM];

int dfs(int v){
  
  int ans = 0;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(child==parent[v])continue;
    parent[child] = v;
    dist[child] = dist[v]+1;
    ans = max(ans,1+dfs(child));
  }
  return (longest[v] = ans);
}

int main(){
  
  int n,x;
  cin>>n>>x;
  
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  dist[1] = 0;
  dfs(1);
  int ans = 2*(longest[x]+dist[x]);
  int counter = 0;
  while(true){
    counter++;
    if(dist[parent[x]]<=counter)break;
    x = parent[x];
    ans = max(ans,2*(longest[x]+dist[x]));
  }
  cout<<ans<<endl;
}

