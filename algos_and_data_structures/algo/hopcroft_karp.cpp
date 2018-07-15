#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007
#define NIL 0

using namespace std;

int m,n;
vi pairU(NUM),pairV(NUM),dist(NUM);
vii graph(NUM);

bool bfs(){

  queue< int > Q;
  for(int u = 1;u<=m;u++)
    if(pairU[u] == NIL){ dist[u] = 0; Q.push(u);}
    else dist[u] = INT_MAX;
    
  dist[NIL] = INT_MAX;
  while(!Q.empty()){
    int u = Q.front();
    Q.pop();
    if(dist[u] < dist[NIL]){
      for(int i=0;i<graph[u].size();i++){
        int v = graph[u][i];
        if(dist[pairV[v]] == INT_MAX){
          dist[pairV[v]] = dist[u] +1;
          Q.push(pairV[v]);
        }
      }
    }
  
  }
  return (dist[NIL] != INT_MAX);
}

bool dfs(int u){
  
  if(u != NIL){
    for(int i=0;i<graph[u].size();i++){
      int v= graph[u][i];
      if(dist[pairV[v]] == dist[u]+1){
        if(dfs(pairV[v]) == true){
          pairV[v] = u;
          pairU[u] = v;
          return true;
        }
      }
    }
    dist[u] = INT_MAX;
    return false;
  }
  return true;
}

int hopcroftKarp(){

  for(int i=0;i<m;i++) pairU[i] = NIL;
  for(int i=0;i<n;i++) pairV[i] = NIL;
  
  int ans = 0;
  while(bfs()){
    for(int u=1;u<=m;u++) if(pairU[u] == NIL && dfs(u)) ans++;
  }
  return ans;
}


int main(){
  
  int x;
  cout<<"Enter the size of the two sets and the number of edges"<<endl;
  cin>>m>>n>>x;
  cout<<"Enter the edges one by one"<<endl;
  for(int i=0;i<x;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  cout<<hopcroftKarp()<<endl;
}
