#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
#define vii vector< vi >

using namespace std;


int main(){
  
  faster
  lld n,m,k;
  cin>>n>>m>>k;
  vi color(n+1);
  
  for(int i = 1;i<=n;i++) cin>>color[i];
  
  vii input(n+1);
  for(int i = 1;i<=m;i++){
    lld a,b;
    cin>>a>>b;
    input[a].push_back(b);
    input[b].push_back(a);
  }

  lld sum = 0;
  bool visited[n+1];
  for(int i = 1;i<=n;i++)
    visited[i] = false;
    
  for(int i = 1;i<=n;i++){
    if(visited[i])
      continue;
    
    stack< lld > dfs;
    dfs.push(i);
    map< lld ,lld > col;
    lld maxm = 0;
    lld tot = 0;
    
    while(dfs.size()){
      int top = dfs.top();
      dfs.pop();
      visited[top] = true;
      col[color[top]]++;
      maxm = max(maxm,col[color[top]]);
      tot++;
      for(int j = 0;j<input[top].size();j++){
        lld child = input[top][j];
        if(!visited[child]) 
          dfs.push(child);
      }
    }
    sum += (tot-maxm);
  }
  
  cout<<sum<<endl;
  
}
