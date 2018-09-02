#include<bits/stdc++.h>
#define vi vector< int >
#define NUM 100007
#define vii vector< vi >

using namespace std;

vii adj(NUM),adj_inv(NUM);
bool visited[NUM],visited_inv[NUM];
stack< int > s;

int scc[NUM];
int counter = 1;

void add_edges(int a,int b){adj[a].push_back(b);adj_inv[b].push_back(a);}

void dfs_first(int u){ //kosaraju first dfs
  if(visited[u])return;
  visited[u] = 1;
  for(int i=0;i<adj[u].size();i++) dfs_first(adj[u][i]);
  s.push(u);
}

void dfs_second(int u){ //kosaraj second dfs
  if(visited_inv[u])return;
  visited_inv[u] = 1;
  for(int i=0;i<adj_inv[u].size();i++)dfs_second(adj_inv[u][i]);
  scc[u] = counter;
}

void is2sat(int n,int m,int a[],int b[]){
  for(int i=0;i<m;i++){
    if(a[i]>0 && b[i]>0){add_edges(a[i]+n,b[i]);add_edges(b[i]+n,a[i]);}
    else if(a[i]>0 && b[i]<0){add_edges(a[i]+n,n-b[i]);add_edges(-b[i],a[i]);}
    else if(a[i]<0 && b[i]>0){add_edges(-a[i],b[i]);add_edges(b[i]+n,n-a[i]);}
    else {add_edges(-a[i],n-b[i]);add_edges(-b[i],n-a[i]);}
  }
  for(int i=1;i<=2*n;i++)if(!visited[i])dfs_first(i);
  while(s.size()){
    int n=s.top();s.pop();
    if(!visited_inv[n]){dfs_second(n);counter++;}
  }
  for(int i=1;i<=n;i++)
    if(scc[i] == scc[i+n]){
      cout<<" The given expression is unsatisfiable "<<endl;return;
    }
  cout<<"The given expression is satisfiable."<<endl;
  return;
}
int main(){
  int n=5,m=7;
  int a[] = {1,-2,-1,3,-3,-4,-3};
  int b[] = {2,3,-2,4,5,-5,4};
  is2sat(n,m,a,b);
  return 0;
}
