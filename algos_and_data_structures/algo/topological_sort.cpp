#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;

vii graph(NUM);
int n;
bool visited[NUM];
vector< int > ans;

void topologicalSort(int v){
  
  visited[v] = true;
  for(int i=0;i<graph[v].size();i++){
    int child  = graph[v][i];
    if(!visited[v]) topologicalSort(child);
  }
  ans.push_back(v);
}


int main(){
  
  n = 6;
  for(int i=0;i<n;i++) visited[i] = false;
  graph[5].push_back(2);
  graph[5].push_back(0);
  graph[4].push_back(0);
  graph[4].push_back(1);
  graph[2].push_back(3);
  graph[3].push_back(1);
  
  for(int i=0;i<n;i++)if(visited[i] == false) topologicalSort(i);
  
  cout<<"Topological order is"<<endl;
  for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<" ";
  cout<<endl;
}


