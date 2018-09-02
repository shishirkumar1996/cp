#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;

vii graph(NUM);
int n;

void add(int x,int y){ graph[x].push_back(y);graph[y].push_back(x); }

void greedyColoring(){

  int result[n];
  result[0] = 0;
  for(int u=1;u<n;u++) result[u] = -1;
  
  bool available[n];
  for(int cr = 0;cr<n;cr++) available[cr] = false;
  
  for(int u=1;u<n;u++){
    for(int i=0;i<graph[u].size();i++){
      int v = graph[u][i];
      if(result[v] != -1)available[result[v]] = true;
    }  
    int cr;
    for(cr = 0;cr<n;cr++)if(available[cr]==false)break;
    
    result[u] = cr;
    for(int i=0;i<graph[u].size();i++){
      int v = graph[u][i];
      if(result[v] != -1) available[result[i]] = false;
    }
  }
  
  for(int u=0;u<n;u++)cout<<"Vertex "<<u<<" ----> color "<<result[u]<<endl;
}

int main(){

  n = 5;
  add(0,1),add(0,2),add(1,2),add(1,3),add(2,3),add(3,4);
  cout<<"Coloring of graph is "<<endl;
  greedyColoring();
}
