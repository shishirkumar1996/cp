#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = "; fr(_,0,n) cerr<<a[_]<<' ';cerr<<'\n';}
#define TM
#define MAXM 300009

using namespace std;

int flag;

vii graph(MAXM);
lld n,x,y;
lld sub_size;
int subtree=0;

int dfs(int v,int p){
  if(v==y){ flag = 1;sub_size = 1;subtree = 1;}
  int sum = 1;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(child==p)continue;
    int l  = dfs(child,v);
    sum += l;
    if(subtree)sub_size += l;
  }
  if(v==y){ subtree=0; }
  return sum;    
}


int main(){

  cin>>n>>x>>y;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);graph[b].push_back(a);
  }
  
  lld num = 1;
  for(int i=0;i<graph[x].size();i++){
    flag = 0;
    int z = dfs(graph[x][i],x);
    if(!flag)num += z;
  }
  cout<<n*(n-1)-num*sub_size<<endl;
  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" .s\n";
  #endif
}
