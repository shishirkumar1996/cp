#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define NUM 5001
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

vii graph(NUM);
bool visited[NUM];
int n,m,s;
void dfs(int v){
  visited[v] = true;
  for(int i=0;i<graph[v].size();i++)if(!visited[graph[v][i]])dfs(graph[v][i]); 
}
stack< int > temp;

void topo_dfs(int v){
  visited[v] = true;
  for(int i=0;i<graph[v].size();i++)if(!visited[graph[v][i]])
    topo_dfs(graph[v][i]);
  temp.push(v);
}

vi topo(){
  for(int i=1;i<NUM;i++)visited[i] = false;
  for(int i=1;i<=n;i++)if(!visited[i]) topo_dfs(i);
  for(int i=1;i<NUM;i++)visited[i] = false;
  vi ans;
  while(temp.size()){
    ans.push_back(temp.top());temp.pop();
  }
  return ans;
}


int main(){

  cin>>n>>m>>s;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
  }
  int num = 0;
  vi x = topo();
  dfs(s);
  for(int i=0;i<x.size();i++){
    int y = x[i];
    if(!visited[y]){ num++; dfs(y); }  
  }
  cout<<num<<'\n';
}
