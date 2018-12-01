#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define NUM 300007

using namespace std;


vector< int > process;
vii graph;
bool visited[NUM];
bool stacked[NUM];

bool dfs(int v){

  visited[v] =true;
  stacked[v] = true;
  for(int i = 0;i<graph[v].size();i++){
    int u = graph[v][i];
    if(stacked[u]) return false;
    if(!visited[u]){
      bool ans = dfs(u);
      if(!ans) return false;
    }
  }
  process.push_back(v);
  stacked[v] = false;
  return true;
}

int main(){

  int n,m;
  string input;
  cin>>n>>m>>input;
  
  graph.resize(n+1);
  for(int i = 0;i<m;i++){
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
  }
  for(int i = 1;i<=n;i++) visited[i] = stacked[i] = false;
  
  for(int i = 1;i<=n;i++) if(!visited[i]){
    bool ans = dfs(i);
    if(!ans){ cout<<-1<<endl;return 0;}
  }
  
  int dp[n+1][26];
  for(int i = 1;i<=n;i++) for(int j= 0;j<26;j++) dp[i][j]= 0;
 
  int ans = 0;
  for(int i = 0;i<process.size();i++){
    int vertex = process[i];
    int x = input[vertex-1]-'a';
    dp[vertex][x] += 1;
    ans = max(ans,dp[vertex][x]);
    for(int j  = 0;j<graph[vertex].size();j++){
      int child = graph[vertex][j];
      for(int k= 0;k<26;k++){
        if(k==x) dp[vertex][k] = max(dp[child][k]+1,dp[vertex][k]);
        else dp[vertex][k] = max(dp[child][k],dp[vertex][k]);
        ans = max(ans,dp[vertex][k]);
      }
    }
  }
  cout<<ans<<endl;

}
