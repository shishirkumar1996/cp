#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;

int start[NUM],end[NUM];
vii graph(NUM);

int timer = 0;

void dfs(int v,int p=-1){
  start[v] = timer++;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(child==p)continue;
    dfs(child,v);
  }
  end[v] = timer-1;
}

int main(){
  
  int n;
  cin>>n;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b); graph[b].push_back(a);
  }
  
  dfs(0);
  for(int i=0;i<n;i++)cout<<start[i]<<" "<<end[i]<<endl;

}
