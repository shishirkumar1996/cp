#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int,int >

using namespace std;

int n,m,q;
char input[1001][1001];
bool visited[1001][1001];
int output[1001][1001];

int r[] = {-1,0,1,0};
int c[] = {0,1,0,-1};
int val;
stack< pr > process;

void dfs(int row,int col){
  visited[row][col] = true;  
  process.push(make_pair(row,col));
  for(int i=0;i<4;i++){
    int x = row+r[i];
    int y= col+c[i];
    if(x<0||x>=n||y<0||y>=m||visited[x][y])continue;
    if(input[x][y]=='*')val++;
    else dfs(x,y);
  }
}

int main(){
  
  faster
  cin>>n>>m>>q;
  for(int i=0;i<n;i++)for(int j=0;j<m;j++){ 
    cin>>input[i][j];visited[i][j] = false;
  }
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(visited[i][j]||input[i][j]=='*')continue;
      dfs(i,j);
      while(process.size()){
        int f = process.top().first;
        int s = process.top().second;
        process.pop();
        output[f][s] = val;
      }
      val = 0;
    }
  }
  
  for(int i=1;i<=q;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    cout<<output[a][b]<<'\n';
  }
  

}
