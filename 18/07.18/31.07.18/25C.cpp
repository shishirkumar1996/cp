#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n;
  cin>>n;
  
  int graph[n+1][n+1];
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>graph[i][j];
  
  int k;
  cin>>k;
  
  for(int i=0;i<k;i++){
    int a,b,c;
    cin>>a>>b>>c;
    graph[a][b] = graph[b][a] = min(graph[a][b],c);
    lld ans = 0;
    for(int x=1;x<=n;x++)
      for(int y=1;y<=n;y++){
        graph[x][y] = graph[y][x] = min(graph[x][y],min(graph[x][a]+graph[a][b]+graph[b][y],graph[x][b]+graph[b][a]+graph[a][y]));
        ans += graph[x][y];
      }  
    cout<<ans/2<<" ";
  }
  cout<<endl;
}
