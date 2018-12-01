#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< int >
#define vii vector< vi >
#define pr pair< int,int >
#define vp vector< pr >
#define NUM 200007

using namespace std;

vii graph(NUM);
int timer;
int n;
vi disc(NUM),size(NUM);
vp order;


int dfs(int v){
  int s = 1;
  disc[v] = ++timer;
  order.push_back(make_pair(disc[v],v));
  for(int i=0;i<graph[v].size();i++)s+= dfs(graph[v][i]);
  return size[v] = s;
}


int main(){
  timer = 0;
  
  int n,q;
  cin>>n>>q;
  for(int i=2;i<=n;i++){
    int a;
    cin>>a;
    graph[a].push_back(i);
  }
  
  for(int i=1;i<=n;i++) sort(graph[i].begin(),graph[i].end());
  
  size[1] = dfs(1);
  sort(order.begin(),order.end());

  for(int i=1;i<=q;i++){
    int u,k;
    cin>>u>>k;
    int t = disc[u];
    t = t+k-1;
    if(k>size[u]) cout<<-1<<endl;
//    if(u==7)cout<<disc[u]<<" timere "<<t<<endl;
    else
    cout<<order[t-1].second<<endl;
  }  

}
