#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;

int n;
vii graph(NUM);
bool visited[NUM];


void bfs(){
  
  for(int i=0;i<=n;i++) visited[i] = false;
  queue< int > q;
  visited[1] = true;
  q.push(1);
  
  while(q.size()){
    int front = q.front();
    cout<<front<<" ";
    q.pop();
    
    for(int i=0;i<graph[front].size();i++){
      int child = graph[front][i];
      if(!visited[child]){
        visited[child] = true;
        q.push(child);
      }
    }
  }
  cout<<endl;
}

int main(){
  
  int m;
  cout<<"Enter the number of vertices and edges"<<endl;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  bfs();
}
