#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define NUM 100007
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

bool visited[NUM];
int graph[NUM];

int dfs(int v){
  if(visited[v])return 0;
  visited[v] = true;
  return dfs(graph[v])+1;
}


int main(){
  int n;
  cin>>n;
    
  for(int i=1;i<=n;i++) cin>>graph[i];
  
  vi process;
  for(int i=0;i<NUM;i++)visited[i] = false;
  
  for(int i=1;i<=n;i++)if(!visited[i]) process.push_back(dfs(i));

  sort(process.begin(),process.end());
  reverse(process.begin(),process.end());
  
  if(process.size()==1){cout<<process[0]*process[0]<<'\n';return 0;}
  lld ans = (process[0]+process[1])*(process[0]+process[1]);
  for(int i=2;i<process.size();i++) ans += (process[i]*process[i]);
  cout<<ans<<endl;
}
