#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define pr pair< lld,lld >
#define vp vector< pr >

using namespace std;

int main(){

  faster
  int n,m;
  cin>>n>>m;
  
  vii graph(n+1);
  vi value(n+1);
  int parent[n+1];
  vi change(n+1);
  
  for(int i=1;i<=n;i++)cin>>value[i];
  
  for(int i=1;i<=n-1;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for(int i=1;i<=n;i++){
    parent[i] = -1;
    change[i] = 0;
  }
  
  stack< int > process;
  process.push(1);
  
  while(process.size()){
    int top = process.top();
    process.pop();
    for(int i = 0;i<graph[top].size();i++){
      int vertex = graph[top][i];
      if(vertex==parent[top]) continue;
      parent[vertex] = top;
      process.push(vertex);
    }
  }
  
  for(int i= 1;i<=m;i++){
    int type;
    cin>>type;
    if(type==1){
      int v,val;
      cin>>v>>val;
      change[v] += val;
//      cout<<v<<" "<<change[v]<<endl;
    }  else {
      int v;
      cin>>v;
      lld ans = value[v]+change[v];
      int temp = v;
      int x = -1;
      while(true){
        int p = parent[temp];
        if(p==-1) break;
        ans += x*change[p];
        temp = p;
        x = (x==-1)?1:-1;
      }
      cout<<ans<<endl;
    }
  }
}
