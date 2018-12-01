#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;

vii graph(107);

int num_visited = 0;
bool visited[107];
void dfs(int v){
  visited[v] = true;
  num_visited++;
  for(int i=0;i<graph[v].size();i++){
    int child=graph[v][i];
    if(visited[child])continue;
    dfs(child);
  }  
}

int main(){

  int n,m;
  cin>>n>>m;
  
  for(int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b); graph[b].push_back(a);
  }
  dfs(1);
  if(num_visited==n && n==m)cout<<"FHTAGN!"<<endl;
  else cout<<"NO"<<endl;

}
