#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
#define vii vector< vi >

using namespace std;


int main(){
  faster
  int n,m;
  cin>>n>>m;
  
  vii input(n+1);
  for(int i = 1;i<=m;i++){
    lld a,b;
    cin>>a>>b;
    input[a].push_back(b);
    input[b].push_back(a);
  }
  
  int visited[n+1];
  for(int i= 1;i<=n;i++)  visited[i] = false;
  
  lld ans = 0;
  
  for(int i = 1;i<=n;i++){
    if(visited[i] == true)
      continue;
    
    lld vertex = 0,edge = 0;
    stack< lld > dfs;
    dfs.push(i);
    visited[i] = true;
    
    while(dfs.size()){
      
      lld top = dfs.top();
      dfs.pop();
      vertex++;
//      cout<<top<<endl;
      edge += input[top].size();
      
      for(int j = 0;j<input[top].size();j++){
        lld child = input[top][j];
        if(!visited[child]){ // this can cause multiple vertices in the graph
          dfs.push(child);
          visited[child] = true;
        }
      }
    
    }
    edge = edge/2;
    if(vertex > edge) ans++;
  }
  cout<<ans<<endl;
  
}
