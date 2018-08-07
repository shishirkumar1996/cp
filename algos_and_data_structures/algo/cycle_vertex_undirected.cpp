#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;

vii graph(NUM);
int parent[NUM],cycle[NUM];
int n;
bool visited[NUM];

void add_edge(int u,int v){graph[u].push_back(v);graph[v].push_back(u);}

void dfs(int v,int p=-1){
  if(visited[v]){
    cycle[v] = 1;
    int temp = parent[v];
    while(temp != v){cycle[temp] = 1;temp = parent[temp];}
    return;
  }
  visited[v] = true;
  for(int i=0;i< graph[v].size();i++){
    int child = graph[v][i];
    if(p==child)continue;
    parent[child] = v;
    dfs(child,v);
  }
}

int main(){
  n = 8;
  add_edge(0,1);add_edge(1,2);add_edge(2,3);add_edge(0,4);add_edge(3,0);
  add_edge(4,5);add_edge(2,6);add_edge(6,7);add_edge(7,2);
  for(int i=0;i<n;i++){
    parent[i]=-1;
    cycle[i] = 0;
    visited[i] = false;
  }
  
  dfs(0); // assumed to be a tree and not a forest
  for(int i=0;i<n;i++)cout<<cycle[i]<<" ";
  cout<<endl;
}
