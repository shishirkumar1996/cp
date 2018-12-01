#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vc vector< char >
#define vcc vector< vc >
#define pr pair< int, int >
#define ppr pair< int , pr >

using namespace std;



int main(){
  
  faster
  int row[] = {0,1,0,-1};
  int col[] = {-1,0,1,0};
  
  int r,c;
  cin>>r>>c;
  char input[r][c];
  int dist[r][c];
  pr start,end;
  for(int i= 0;i<r;i++) for(int j = 0;j<c;j++) {
  
    cin>>input[i][j];
    if(input[i][j] == 'E') end = make_pair(i,j);
    if(input[i][j] == 'S') start = make_pair(i,j);
    dist[i][j] = INT_MAX;
  }
  
  queue< pr > process;
  bool visited[r][c];
  for(int i =0;i<r;i++) for(int j = 0;j<c;j++) visited[i][j] = false;
  process.push(make_pair(end.first,end.second));
  dist[end.first][end.second] = 0;
  
  visited[end.first][end.second] = true;
  
  while(process.size()){
    pr top = process.front();
    process.pop();
    int x = top.first,y = top.second;
    for(int i = 0;i<4;i++){
      int child_x = x+row[i];
      int child_y = y+col[i];
      if(child_x <0 || child_x >=r || child_y <0 || child_y >= c || input[child_x][child_y] == 'T')continue;
      if(!visited[child_x][child_y]){
        visited[child_x][child_y] = true;
        dist[child_x][child_y] = dist[x][y]+1;
        process.push(make_pair(child_x,child_y));
      }
    }
  }
  lld ans = 0,tot_dist = dist[start.first][start.second];
  for(int i= 0;i<r;i++) for(int j=0;j<c;j++){
    if(input[i][j] == 'E' || input[i][j] == 'S' || input[i][j] == 'T')continue;
    if(dist[i][j] <= tot_dist) ans += (input[i][j] -'0');
  }  

  cout<<ans<<endl;
}
