#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = ";for(int i=0;i<n;i++) cerr<<a[i]<<' '; cerr<<'\n'; }
#define TM

using namespace std;


int main(){

  int r[] = {-1,0,1,0};
  int c[] = {0,1,0,-1};
  int w,h;
  cin>>w>>h;
  char input[w][h];
  
  bool visited[w][h][4];
  int start_r,start_c,start_d;
  for(int i=0;i<w;i++)for(int j=0;j<h;j++){
    cin>>input[i][j];
    if(input[i][j]!='.' && input[i][j] != '*'){
      start_r = i,start_c = j;
      if(input[i][j]=='U')start_d = 0;
      else if(input[i][j]=='R') start_d = 1;
      else if(input[i][j]=='D') start_d = 2;
      else if(input[i][j]=='L') start_d = 3;
    }
  }
  for(int i=0;i<w;i++)for(int j=0;j<h;j++)for(int k=0;k<4;k++)visited[i][j][k] = false;
  
  int ans = 0;
  while(true){
//    trace(start_r);trace(start_c);trace(start_d);
    if(visited[start_r][start_c][start_d])break;
    if(!visited[start_r][start_c][0] && !visited[start_r][start_c][1] && !visited[start_r][start_c][2] && !visited[start_r][start_c][3])ans++;
    visited[start_r][start_c][start_d] = true;
    
    int next_r = start_r+r[start_d],next_c = start_c+c[start_d];
    if(next_r<0 || next_r>=w || next_c<0 || next_c>=h || input[next_r][next_c]=='*')start_d = (start_d+1)%4;
    else {start_r = next_r;start_c = next_c;}
  }
  cout<<ans<<endl;

  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s\n";
  #endif

}
