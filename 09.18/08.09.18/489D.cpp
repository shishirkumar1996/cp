#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int main(){

  faster
  int n,m;
  cin>>n>>m;
  vii graph(n+1),inv_graph(n+1);
  
  for(int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);inv_graph[b].push_back(a);
  }
  for(int i=1;i<=n;i++){
    sort(graph[i].begin(),graph[i].end());
    sort(inv_graph[i].begin(),inv_graph[i].end());
  }  
  
  lld ans = 0;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
      if(i==j)continue;
      int index1 = 0,index2 = 0;
      int same = 0;
      while(index1 < graph[i].size() && index2 < inv_graph[j].size()){
        int x = graph[i][index1];
        int y = inv_graph[j][index2];
        if(x>y)index2++; else if(x<y) index1++;
        else if(x==y){same++;index1++;index2++;}
      }
      if(same<=1)continue;
      ans += (same*(same-1))/2;
    }
  cout<<ans<<endl;
}
