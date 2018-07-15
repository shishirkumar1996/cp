#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >

using namespace std;


int n,l;
vii graph,up;
vi tin,tout;
int timer;


void dfs(int v,int p=0){
  tin[v] = ++timer;
  up[v][0] = p;
  for(int i=1;i<=l;i++) up[v][i] = up[up[v][i-1]][i-1];
  
  for(int i=0;i<graph[v].size();i++){
    int to = graph[v][i];
    if(to != p) dfs(to,v);
  }

  tout[v] = ++timer;
}

bool upper(int a,int b){return (tin[a]<=tin[b] &&  tout[a]>=tout[b]);}

int lca(int a,int b){
  if(upper(a,b)) return a;
  if(upper(b,a)) return a;
  for(int i=l;i>=0;i--) if(!upper(up[a][i],b)) a=up[a][i];
  return up[a][0];
}

int main(){
  
  cout<<"Enter the number of vertices"<<endl;
  cin>>n;
  graph.resize(n);
  cout<<"Enter the edges"<<endl;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  tin.resize(n),tout.resize(n),up.resize(n);
  
  //this is the method of defining depth here, can be different also
  l = 1;
  while((1<<l)<=n) ++l;
  for(int i=0;i<n;i++) up[i].resize(l+1);
  
  dfs(0);
  
  cout<<"Enter the vertices to find their lowest common ancestors"<<endl;
  int a,b;
  cin>>a>>b;
  cout<<lca(a,b)<<endl;
}
