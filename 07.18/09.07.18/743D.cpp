#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define MINM (lld)(-1e15-7)

using namespace std;

vii graph(200007);
bool visited[200007];
lld val[200007];
lld maxm,ans;

lld dfs(int vertex){
  
//  cout<<vertex<<endl;
  visited[vertex] = true;
  lld temp = maxm,process = val[vertex];
  for(int i = 0;i<graph[vertex].size();i++){
    int child = graph[vertex][i];
//    cout<<child<<endl;
    if(visited[child])continue;
    process += dfs(child);
  }
  if(temp != MINM)ans = max(ans,process+temp);
  
  maxm = max(maxm,process);
  return process;
}



int main(){

  int n;
  cin>>n;
  
  for(int i=1;i<=n;i++) cin>>val[i];
  for(int i = 1;i<n;i++){
    lld a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for(int i=1;i<=n;i++) visited[i] = false;
  maxm = ans = MINM;
  
  dfs(1);
  if(ans==MINM)cout<<"Impossible"<<endl;
  else cout<<ans<<endl;
}
