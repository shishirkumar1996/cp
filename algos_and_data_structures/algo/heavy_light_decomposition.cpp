#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;


vii graph(NUM);
int chain_no;
vi chain_head(NUM),chain_pos(NUM),chain_ind(NUM),chain_size(NUM),subsize(NUM);
int n;

int dfs(int v,int p=-1){
  
  int size = 1;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(child == p)continue;
    size += dfs(child,v);
  }
  return (subsize[v] = size);
}

void hld(int cur,int p=-1){
  if(chain_head[chain_no] == -1)chain_head[chain_no] = cur;
  chain_ind[cur]  = chain_no;
  chain_pos[cur] = chain_size[chain_no];
  chain_size[chain_no]++;
  
  int ind = -1,mai = -1;
  for(int i=0;i<graph[cur].size();i++){
    int child = graph[cur][i];
    if(child==p)continue;
    if(subsize[child]>mai){
      mai = subsize[child];
      ind = i;
    }
  }
  if(ind>=0) hld(graph[cur][ind],cur);
  for(int i=0;i<graph[cur].size();i++){
    int child = graph[cur][i];
    if(child==p)continue;
    if(i != ind){ 
      chain_no++;
      hld(child,cur);
    }
  }
}

int main(){
  cin>>n;
  for(int i=0;i<NUM;i++) chain_head[i] = -1;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  // 0 is assumed to be the root here
  int root = 0;
  dfs(root);
  hld(root);
  cout<<"number of chains are "<<chain_no+1<<endl;
  cout<<"the head of the chains are "<<endl;
  for(int i=0;i<=chain_no;i++)cout<<chain_head[i]<<endl;
}
