#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;

vii graph(NUM);

bool visited[NUM],ap[NUM];
vi disc(NUM),low(NUM),parent(NUM);
int timer,n;


void add(int x,int y){
  graph[x].push_back(y);
  graph[y].push_back(x);
}

void articulation_pt(int u){
  visited[u] = true;
  int children = 0;
  disc[u] = low[u] = ++timer;
  
  for(int i=0;i<graph[u].size();i++){
    int child = graph[u][i];
    if(!visited[child]){
      children++;parent[child] = u;articulation_pt(child);
      low[u] = min(low[u],low[child]);
    
      if(parent[u]==-1 && children > 1)ap[u] = true;
      if(parent[u] != -1 && low[child]>=disc[u]) ap[u] = true;
    } else if(child != parent[u]) low[u] = min(low[u],disc[child]);
  }
}

int main(){

  timer = 0;
  n = 5;
  add(1,0),add(0,2),add(2,1),add(0,3),add(3,4);
  
  
  for(int i=0;i<n;i++){ parent[i] = -1;visited[i] = false;ap[i]=false; }
  
  for(int i=0;i<n;i++)
    if(visited[i] == false) articulation_pt(i);
    
  cout<<"Articulation points are "<<endl;
  for(int i=0;i<n;i++)if(ap[i])cout<<i<<" ";
  cout<<endl;
}
