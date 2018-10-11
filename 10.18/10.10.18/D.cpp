#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = "; for(int i=0;i<n;i++)cerr<<a[i]<<' ';cerr<<'\n';}
#define NUM 1000

using namespace std;

vii graph(NUM),inv_graph(NUM);
map< string,int > country;
int size = 0;

bool visited[NUM];
bool dfs(int num,int search){
  if(num==search)return true;
  visited[num] = true;
  for(int i=0;i<graph[num].size();i++){
    if(visited[graph[num][i]])continue;
    if(dfs(graph[num][i],search))return true;
  }
  return false;
}
bool inverse_dfs(int num,int search){
  if(num==search)return true;
  visited[num] = true;
  for(int i=0;i<inv_graph[num].size();i++){
    if(visited[inv_graph[num][i]])continue;
    if(dfs(inv_graph[num][i],search))return true;
  }
  return false;
}

int main(){

  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    string a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    if(!country[a])country[a] = ++size;
    if(!country[e])country[e] = ++size;
    graph[country[e]].push_back(country[a]);
  }
  
  for(int i=0;i<m;i++){
    string a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    if(!country[a])country[a] = ++size;
    if(!country[e])country[e] = ++size;
    for(int i=0;i<NUM;i++)visited[i] = false;
    bool ans;
    ans = dfs(country[e],country[a]);
    if(ans){cout<<"Fact\n";continue;}
    for(int i=0;i<NUM;i++)visited[i] = false;
    ans = dfs(country[a],country[e]);
    if(ans) cout<<"Alternative Fact\n"; else cout<<"Pants on Fire\n";
  }
  
  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif

}
