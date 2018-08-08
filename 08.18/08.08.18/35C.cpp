#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int ,int >
#define ppr pair< pr,int >
#define NUM 2007

using namespace std;

int process[NUM][NUM];
bool visited[NUM][NUM];

int main(){

  faster
  int n,m;
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  
  scanf("%d%d",&n,&m);

  int r_c[] = {-1,0,1,0};
  int c_c[] = {0,1,0,-1};
  
  for(int i=0;i<=n;i++)for(int j=0;j<m;j++)
    process[i][j] = 0,visited[i][j]= false;
  
  queue< ppr > q;
  int k;
  scanf("%d",&k);
  for(int i=1;i<=k;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    visited[a][b] = true;
    q.push(make_pair(make_pair(a,b),0));
  }
  int max = -1,max_row,max_col;
  
  while(q.size()){
    int r= q.front().first.first;
    int c = q.front().first.second;
    int t = q.front().second;
    if(max<process[r][c]){
      max= process[r][c];max_row = r;max_col =c;
    }
    q.pop();
    for(int i=0;i<4;i++){
      int row = r_c[i]+r,col = c_c[i]+c;
      if(row>0 && row<n+1 && col>0 && col<m+1 && !visited[row][col]){
        visited[row][col] = true;
        process[row][col] =t+1;
        q.push(make_pair(make_pair(row,col),process[row][col]));
      }
    }
  }
  printf("%d %d\n",max_row,max_col);
}
