#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;

vii graph(107);

int main(){

  int n,m;
  cin>>n>>m;

  int vertices = n,edges = m;
  int degree[n+1];
  bool visited[n+1];
  for(int i=0;i<=n;i++){ degree[i] = 0;visited[i] = false;}
  
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
    degree[a]++;degree[b]++;
  }
  
  set< int > ones;
  for(int i=1;i<=n;i++) if(degree[i]==1)ones.insert(i);
  
  while(vertices>0 && edges > 0){
    int x = *(set.begin());
    set.erase(set.begin());
    for(int i=0;i<graph[x].size();i++){
      int y = graph[x][i];
      if(index[y]==1){cout<<"NO"<<endl;return 0;}
      index
    }  
      
  }

}
