#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define NUM (lld)(1e5+7)

using namespace std;

int ans = 0;
vii graph(NUM);

int dfs(int v,int p=-1){

  int y = 1;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(child==p)continue;
    int x = dfs(child,v);
    if(x%2==0)ans++;
    y += x;
  }
  return y;
}


int main(){

  int n;
  cin>>n;
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  if(n%2==1){ cout<<-1<<endl;return 0;}  
  
  dfs(1);
  cout<<ans<<endl;
}
