#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vc vector< char >
#define vcc vector< vc >
#define pr pair< int,int >
using namespace std;

int row[4] = {-1,0,1,0};
int col[4] = {0,1,0,-1};


string calc(int n,int m,vcc input,int init_r,int init_c,int final_r,int final_c){
  
  int visited[n+1][n+1];
  for(int i = 1;i<=n;i++)
    for(int j = 1;j<=m;j++)
      visited[i][j] = (input[i][j]=='X')?1:0;
    
  stack< pr > dfs;
  dfs.push(make_pair(init_r,init_c));
  
  while(dfs.size()){
    pr top = dfs.top();
    dfs.pop();
    int r = top.first;
    int c = top.second;
    visited[r][c]++;
//    cout<<r<<" "<<c<<endl;
    for(int i = 0;i<4;i++)
      if(r+row[i]>0 && r+row[i]<=n && c+col[i]>0 && c+col[i] <= m && visited[r+row[i]][c+col[i]] < 2){
        dfs.push(make_pair(r+row[i],c+col[i]));
        cout<<visited[r+row[i]][c+col[i]]<<endl;
      } 
  }
  cout<<visited[final_r][final_c]<<endl;
  if(visited[final_r][final_c]==2)
    return "YES";
  else
    return "NO";
  
}

int main(){
  faster
  int n,m;
  cin>>n>>m;
  int init_r,init_c,final_r,final_c;
  vcc input(n+1);
  for(int i = 1;i<=n;i++){
    input[i].resize(m+1);
    for(int j = 1;j<=m;j++)
      cin>>input[i][j];
  }
  cin>>init_r>>init_c>>final_r>>final_c;
  cout<<calc(n,m,input,init_r,init_c,final_r,final_c)<<endl;
}
