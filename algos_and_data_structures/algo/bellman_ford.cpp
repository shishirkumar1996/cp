#include<bits/stdc++.h>
#define lld long long int
#define pr pair< int,int >
#define ppr pair< pr,int >
#define vppr vector< ppr >
#define vi vector< int >
#define NUM 100007

using namespace std;

// graph here is represented as array of edges
vppr graph;
int n,m;  // number of vertices and edges respectively
vi dist(NUM);

void bellmanford(int src){
  
  for(int i=0;i<n;i++) dist[i] = INT_MAX;
  dist[src] = 0;
  
  for(int i=1;i<=n-1;i++){
    for(int j=0;j<m;j++){
      int u = graph[j].first.first;   // source
      int v = graph[j].first.second;  // destination
      int weight = graph[j].second; 
      if(dist[u] != INT_MAX && dist[u]+weight < dist[v])
        dist[v] = dist[u]+weight;
    }
  }
  
  for(int i=0;i<m;i++){
    int u= graph[i].first.first; //source
    int v=graph[i].first.second; //destination
    int weight = graph[i].second;
    if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
      cout<<"Graph contains negative weight cycle"<<endl;
  }
  
  cout<<"Distance from source"<<endl;
  for(int i=0;i<n;i++)cout<<i<<" "<<dist[i]<<endl;
}

int main(){
  n = 5,m = 8;
  
  graph.push_back(make_pair(make_pair(0,1),-1));
  graph.push_back(make_pair(make_pair(0,2),4));
  graph.push_back(make_pair(make_pair(1,2),3));
  graph.push_back(make_pair(make_pair(1,3),2));
  graph.push_back(make_pair(make_pair(1,4),2));      
  graph.push_back(make_pair(make_pair(3,2),5));
  graph.push_back(make_pair(make_pair(3,1),1));
  graph.push_back(make_pair(make_pair(4,3),-3));
  
  bellmanford(0);

}

