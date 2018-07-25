#include<bits/stdc++.h>
#define lld long long int
#define vc vector< char >
#define vcc vector< vc >
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int ans[8][8][100];
vcc input(8);
bool present[8][8];

int dfs(int chance,int r,int c,int t){
  if(r==0 && c==7)return 1;
  
  if(chance==0){
    if(r-t>=0 && present[r-t][c])return 0;
    return 1;
  }
  if(ans[r][c][t]!=-1) return ans[r][c][t];
  
  for(int x=-1;x<=1;x++)for(int y=-1;y<=1;y++){
    int row = r+x,col = c+y;
    if(row<0 || row>=8 || col<0 || col>=8) continue;
    if(dfs(0,row,col,t) && dfs(0,row,col,t+1) && dfs(1,row,col,t+1)){
//      cout<<row<<" "<<col<<" "<<t+1<<endl;
      return (ans[r][c][t] = 1);  
    }  
  }
  return ans[r][c][t] = 0;
}

int main(){
  
  faster
  memset(ans,-1,sizeof(ans));
  
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      present[i][j] = false;
      char a;
      cin>>a;
      input[i].push_back(a);
      if(a=='S') present[i][j] = true;
    }
  }
  
  if(dfs(1,7,0,0)==1)cout<<"WIN"<<endl; else cout<<"LOSE"<<endl;

}
