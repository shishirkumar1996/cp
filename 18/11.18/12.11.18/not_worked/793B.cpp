#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int,int >
#define ppr pair< pr,pr >

using namespace std;

int main(){

  int dr[] = {-1,0,1,0};
  int dc[] = {0,1,0,-1};
  int n,m;
  cin>>n>>m;
  char input[n+2][m+2];
  int start_r,start_c,end_r,end_c;
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){ 
    cin>>input[i][j];
    if(input[i][j]=='S'){ start_r = i,start_c = j; }
    if(input[i][j]=='T'){ end_r = i,end_c = j; }
  }
  
  bool visited[n+2][m+2][4] = { false };
  queue< ppr > process;
  process.push(make_pair(make_pair(start_r,start_c),make_pair(0,-1)));
  visited[start_r][start_c][0] = visited[start_r][start_c][1] = visited[start_r][start_c][2] = visited[start_r][start_c][3] = false;
  
  while(process.size()){
    ppr top = process.front();
    int r = top.first.first;
    int c = top.first.second;
    int dir = top.second.second;
    int num = top.second.first;
    cout<<r<<" "<<c<<" "<<num<<" "<<dir<<'\n';
    process.pop();
    for(int i=0;i<4;i++){
      int new_r = r+dr[i],new_c = c+dc[i];
      if(input[new_r][new_c]!='.' && input[new_r][new_c] !=  'T')continue;
      int new_dir = i;
      int new_num = num;
      if(dir != -1 && dir != new_dir)new_num++;
      if(new_num>2||visited[new_r][new_c][new_dir])continue;
      visited[new_r][new_c][new_dir] = true;
    process.push(make_pair(make_pair(new_r,new_c),make_pair(new_num,new_dir)));
    }
  }
  if(visited[end_r][end_c][0]||visited[end_r][end_c][1]||visited[end_r][end_c][2]||visited[end_r][end_c][3])cout<<"YES\n"; else cout<<"NO\n";
}
