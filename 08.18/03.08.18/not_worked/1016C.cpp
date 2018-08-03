#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define NUM (lld)(1e6+7)

using namespace std;

lld input[2][NUM];
int n;

lld dfs(int r,int c,int type,int last,int counter){
  
  lld val = 0;
  if(c==n+1||counter==2*n)return 0;
  if(type==0){
    if(last== c) val = max(val,counter*input[r][c]+dfs(r,c+1,0,c,counter+1));
    else{
      val = max(val,max(counter*input[r][c]+dfs(r^1,c,0,c,counter+1),counter*input[r][c]+dfs(r,c+1,1,c,counter+1)));
    }
  } else if(type==1){
    if(c<n) val = counter*input[r][c]+dfs(r,c+1,1,c,counter+1);
    else val = counter*input[r][c]+dfs(r^1,c,-1,c,counter+1);  
  } else if(type==-1){
    val = counter*input[r][c]+dfs(r,c-1,-1,c,counter+1);
  }
  return val;
}



int main(){

  faster
  cin>>n;
  
  for(int i=0;i<2;i++)for(int j=1;j<=n;j++)cin>>input[i][j]; 
  lld ans = dfs(0,1,0,-1,0);
  cout<<ans<<endl;
}
