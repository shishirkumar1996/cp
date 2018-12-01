#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define pr pair< lld,lld >
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';
#define MAXM (lld)(1e9+7)

using namespace std;

int main(){
  
  faster
  int hor[]  = {-1,0,1,0};
  int ver[] = {0,-1,0,1};
  
  lld n,m,r,c,x,y;
  cin>>n>>m>>r>>c>>x>>y;
  
  r--;c--;
  int process_x[n][m],process_y[n][m];
  for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    process_x[i][j] = process_y[i][j] = MAXM;

  process_x[r][c] = process_y[r][c] = 0;
  vector< string >input(n);
  for(int i=0;i<n;i++)cin>>input[i];

  priority_queue< pair< int,int > >temp;
  temp.push(make_pair(r,c));
  while(temp.size()){
    pair< int,int >top = temp.top();
    temp.pop();
    int temp_r = top.first,temp_c = top.second;
    for(int i=0;i<4;i++){
      int next_r = temp_r+ver[i];
      int next_c =  temp_c+hor[i];
      if(next_r<0 || next_r>=n || next_c<0||next_c>=m||input[next_r][next_c]=='*')continue;
      int add_x=0,add_y=0;
      if(i==0){
        if(process_x[temp_r][temp_c]+1<process_x[next_r][next_c] && process_x[temp_r][temp_c]<x) add_x++; else continue;
      } else if(i==2){
          if(process_y[temp_r][temp_c]+1<process_y[next_r][next_c] && process_y[temp_r][temp_c]<y) add_y++; else continue;  
      } else if(i==3||i==1){
        if(!(process_y[temp_r][temp_c]<process_y[next_r][next_c]||process_x[temp_r][temp_c]<process_x[next_r][next_c]))continue;  
      }
      process_x[next_r][next_c] = process_x[temp_r][temp_c]+add_x;
      process_y[next_r][next_c] = process_y[temp_r][temp_c]+add_y;
      temp.push(make_pair(next_r,next_c));
    }
  }
  int ans = 0;
  for(int i=0;i<n;i++)for(int j=0;j<m;j++)
    if(process_x[i][j]<=x && process_y[i][j]<=y)ans++;
   
  cout<<ans<<endl; 
}
