#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
#define pr pair< int,int >
#define vp vector< pr >
#define vip vector< vp >
#define NUM 100007

using namespace std;

vip graph(NUM);
int n,m;
int dist[NUM];

void dijkstra(int v){

  for(int i=0;i<=n;i++)dist[i] = INT_MAX;  
  dist[v] = 0;
  priority_queue< pr > process;
  process.push(make_pair(dist[v],v));
  
  while(process.size()){
    pr top = process.top();
    process.pop();
    int v = top.second;
    int d = top.first;
    for(int i=0;i<graph[v].size();i++){
      int child = graph[v][i].first;
      int distance = graph[v][i].second;
      if(dist[child]> dist[v] + distance){
        dist[child] = dist[v]+distance;
        process.push(make_pair(dist[child],child));
      }
    }
  }
  for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
  cout<<endl;
}

int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    graph[a].push_back(make_pair(b,c));
    graph[b].push_back(make_pair(a,c));
  }
  dijkstra(1);
}
