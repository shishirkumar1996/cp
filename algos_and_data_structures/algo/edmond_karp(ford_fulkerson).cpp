#include<bits/stdc++.h>
#define vi vector< int >
#define NUM 1007

using namespace std;

//adjacency matrix is applied here, need to check for adjacency list soln.
int n,s,t; // number of vertices, source and sink
int graph[NUM][NUM];
int rgraph[NUM][NUM]; //residual graph
vi parent(NUM);

bool bfs(){
    
  bool visited[n];
  memset(visited,false,sizeof(visited));
  
  queue< int > q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;
  
  while(!q.empty()){
    int front = q.front();
    q.pop();
    for(int i=0;i<n;i++){
      if(visited[i] == false && rgraph[front][i] >0 ){
        q.push(i);
        parent[i] = front;
        visited[i] = true;
      }
    }
  }  
  return(visited[t] == true);
}

int fordFulkerson(){
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++) rgraph[i][j] = graph[i][j];
  
  int max_flow = 0;
  while(bfs()){
    int path_flow = INT_MAX;
    for(int v = t;v != s;v=parent[v]){
      int u = parent[v];
      path_flow = min(path_flow,rgraph[u][v]);
    }
    for(int v=t;v!=s;v=parent[v]){
      int u=parent[v];
      rgraph[u][v] -= path_flow;
      rgraph[v][u] += path_flow;
    }
    max_flow += path_flow;
  }
  return max_flow; 
}

int main(){
  
  s=0,t=5,n=6;
  int xgraph[n][n] =  { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
  
  for(int i=0;i<n;i++)for(int j=0;j<n;j++) graph[i][j] = xgraph[i][j];
  
  cout<<fordFulkerson()<<endl;
}
