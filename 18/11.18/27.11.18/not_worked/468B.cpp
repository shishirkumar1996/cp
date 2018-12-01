#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define NUM 100007
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) {cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

vii graph(NUM);
bool visited[NUM];
int ans[NUM];

int dfs(int v,int num){
  visited[v] = true;
  ans[v] = num;
  int s = 1;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(visited[child])continue;
    s += dfs(child,num);
  }
  return s;
}

int main(){
  lld a,b,n;
  cin>>n>>a>>b;
  vi input(n);
  map< lld,int > present;
  for(int i=0;i<n;i++){ cin>>input[i];present[input[i]] = i+1; }
  
  for(int i=0;i<n;i++){
    if(present[a-input[i]])graph[i].push_back(present[a-input[i]]-1);
    if(present[b-input[i]])graph[i].push_back(present[b-input[i]]-1);
  }
  for(int i=0;i<n;i++){ visited[i] = false;ans[i] = -1; }
  for(int i=0;i<n;i++){
    if(visited[i])continue;
    if(!graph[i].size()){ cout<<"NO\n";return 0; }
    if(graph[i].size()>1)continue;
    int num;
    if(input[i]+input[graph[i][0]]==a) num = 0; else num = 1;
    int s = dfs(i,num);
    if(s%2==1){ cout<<"NO\n";return 0; }
  }
  cout<<"YES\n";
  for(int i=0;i<n;i++)cout<<ans[i]<<" ";cout<<'\n';
}
