#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int,int >
#define vp vector< pr >
#define vip vector< vp >
#define NUM 1e5+7

using namespace std;

vip graph(NUM);

lld dfs(int v,int p=-1){
  
  lld maxm = 0;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i].first;
    if(child==p)continue;
    maxm = max(maxm,graph[v][i].second+dfs(child,v));
  }
  return maxm;
}


int main(){
  
  faster
  int n;
  cin>>n;
  lld sum = 0;
  for(int i=0;i<n-1;i++){
    int a,b,c;
    cin>>a>>b>>c;
    graph[a].push_back(make_pair(b,c));
    graph[b].push_back(make_pair(a,c));
    sum += c;
  }
  lld s = dfs(1);
  cout<<2*sum-s<<endl;
}
