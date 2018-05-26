#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
#define vii vector< vi >

using namespace std;


int main(){

  faster
  lld n,m,w;
  cin>>n>>m>>w;
  vii graph(n+1),groups(1001);
  vi weight(n+1),beauty(n+1);
  for(int i= 1;i<=n;i++)cin>>weight[i];
  for(int i =1;i<=n;i++)cin>>beauty[i];
  
  for(int i = 0;i<m;i++){
    lld a,b;
    cin>>a>>b;
    graph[a].push_back(b);graph[b].push_back(a);
  }
  
  stack< lld > dfs;
  bool visited[n+1];
  int group_num = 1;
  for(int i = 0;i<=n;i++) visited[i] = false;
  for(int i = 1;i<=n;i++){
    if(visited[i]) continue;
    
    dfs.push(i);
    while(dfs.size()){
      int top = dfs.top();
      dfs.pop();
      visited[top] = true;
      groups[group_num].push_back(top);
      
      for(int j=0;j<graph[top].size();j++){
        int child = graph[top][j];
        if(!visited[child]) dfs.push(child);
      }
    
    }
    group_num++;
  }
  group_num--;
  lld dp[group_num+1][w+1];
  memset(dp,0,sizeof(dp));
  
  for(int i = 1;i<=group_num;i++){
    for(int j = 1;j<=w;j++){
      dp[i][j] = dp[i-1][j];
      lld weight_sum = 0,beauty_sum = 0;
      for(int k = 0;k<groups[i].size();k++){
        weight_sum += weight[groups[i][k]];
        beauty_sum += beauty[groups[i][k]];
        
        if(j-weight[groups[i][k]]>=0) dp[i][j] = max(dp[i][j],beauty[groups[i][k]]+dp[i-1][j-weight[groups[i][k]]]);
      }
      if(j-weight_sum>=0) dp[i][j] = max(dp[i][j],beauty_sum+dp[i-1][j-weight_sum]);  
    }  
  }
//  cout<<group_num<<endl;
//  for(int i = 1;i<=group_num;i++){
//    for(int j = 1;j<=w;j++) cout<<dp[i][j]<<" ";
//    cout<<endl;
//  }
  
  cout<<dp[group_num][w]<<endl;
  
}
