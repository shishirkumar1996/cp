#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
#define pr pair< int,int >
#define vp vector< pr >
#define vip vector< vp >
#define NUM 100007

using namespace std;

int n,m;

vip graph(NUM);

void prim(){

  int start = 0;
  priority_queue< pr > pq;
  vi dist(n,INT_MAX),parent(n,-1);
  vector< bool > inMST(n,false);
  pq.push(make_pair(0,start));
  
  dist[start] = 0;
  while(pq.size()){ //pick the smallest just like dijkstra
    int u= pq.top().second;
    pq.pop();
    
    inMST[start] = true;
    for(int x =0;x<graph[u].size();x++){
      int v= graph[u][x].first;
      int weight = graph[u][x].second;
      if(inMST[v] == false && dist[v] > weight){
        dist[v] = weight;
        pq.push(make_pair(dist[v],v));
        parent[v] =  u;
      }
    }
  }
  for(int i=1;i<n;i++)cout<<parent[i]<<" "<<i<<endl;
}

int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    graph[a].push_back(make_pair(b,c));
    graph[b].push_back(make_pair(a,c));
  }
  prim();
}

