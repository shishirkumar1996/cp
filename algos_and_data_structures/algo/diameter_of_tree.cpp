#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;

int x,n;
int max_count = 0;
bool visited[NUM];
vii graph(NUM);

void dfs(int v,int ct){
  
  visited[v] = true;
  if(ct>max_count){max_count = ct;x = v;}
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(visited[child])continue;
    dfs(child,ct+1);
  }
}

void diam(){
  for(int i=0;i<n;i++) visited[i] = false;
  dfs(1,0);
  for(int i=0;i<n;i++)visited[i] = false;
  dfs(x,0);
}

int main(){
  n = 5;
  graph[0].push_back(1);graph[1].push_back(0);
  graph[2].push_back(1);graph[1].push_back(2);
  graph[0].push_back(3);graph[3].push_back(0);
  graph[2].push_back(4);  graph[4].push_back(2);

  diam();
  cout<<max_count<<endl;
}
