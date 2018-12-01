#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;

vii graph(NUM);
int parent[NUM];

void dfs(int v,int p=0){
  
  parent[v] = p;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(child==p)continue;
    dfs(child,v);
  }

}

int main(){
  
  int n,r1,r2;
  cin>>n>>r1>>r2;
  
  for(int i=1;i<=n;i++){
    if(i==r1)continue;
    int a;
    cin>>a;
    graph[i].push_back(a);
    graph[a].push_back(i);
  }

  dfs(r2);
  for(int i=1;i<=n;i++)if(parent[i])cout<<parent[i]<<" ";
  cout<<endl;
}
