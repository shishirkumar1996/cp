#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;

vii graph(NUM);
int n,m;
bool visited[NUM];

void dfs(int v){
  visited[v] = true;
  cout<<v<<" ";
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(!visited[child]) dfs(child);
  }
}

int main(){
  
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for(int i=1;i<=n;i++)visited[i] = false;
  dfs(1);
}
