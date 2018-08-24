#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define pr pair< int,int >

using namespace std;

int main(){

  faster
  int dr[] = {-1,0,1,0};
  int dc[] = {0,1,0,-1};
  int n,m,k;
  cin>>n>>m>>k;
  
  char input[n+1][m+1];
  int dist[n+1][m+1];
  
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
    cin>>input[i][j];
    dist[i][j] = INT_MAX;
  }
  
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  
  queue< pr > process;
  process.push(make_pair(x1,y1));
  dist[x1][y1] = 0;
  
  while(process.size()){
    
    pr front = process.front();
    int r= front.first,c=front.second;
    process.pop();
    for(int l=0;l<4;l++)
      for(int i=1;i<=k && r+dr[l]*i>0 && r+dr[l]*i<=n && c+dc[l]*i>0 && c+dc[l]*i<=m;i++)
        if(input[r+dr[l]*i][c+dc[l]*i]=='#'||dist[r+dr[l]*i][c+dc[l]*i]<=dist[r][c])break;
        else if(dist[r+dr[l]*i][c+dc[l]*i]>dist[r][c]+1){
          dist[r+dr[l]*i][c+dc[l]*i] = dist[r][c]+1;
          process.push(make_pair(r+dr[l]*i,c+dc[l]*i));
        }
  }
  if(dist[x2][y2]==INT_MAX)cout<<-1<<endl;
  else cout<<dist[x2][y2]<<endl;
}
