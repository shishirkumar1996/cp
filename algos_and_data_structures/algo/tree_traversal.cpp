#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;

int timer = 0;
vii graph(NUM);
vi in(NUM),out(NUM);

int dfs(int v,int p=-1){
  in[v] = ++timer;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(child==p)continue;
    dfs(child,v);
  }
  out[v] = ++timer;
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);graph[b].push_back(a);
  }
  
  int root = 0;//here 0 is taken as root;
  dfs(0);
  for(int i=0;i<n;i++)cout<<in[i]<<" "; cout<<endl;
  for(int i=0;i<n;i++)cout<<out[i]<<" "; cout<<endl;
}
