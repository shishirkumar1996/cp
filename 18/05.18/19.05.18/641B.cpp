#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int

using namespace std;

int main(){

  faster
  int n,m,q;
  cin>>n>>m>>q;
  
  lld table[n+1][m+1];
  for(int i =0;i<=n;i++) for(int j = 0;j<=m;j++) table[i][j] = 0;
  
  lld query[q][4];
  for(int i = 0;i<q;i++){
    query[i][0] = query[i][1] = query[i][2] = query[i][3] = -1;
    cin>>query[i][0];
    if(query[i][0]==1||query[i][0]==2) cin>>query[i][1];
    else cin>>query[i][1]>>query[i][2]>>query[i][3];
  }
  
  for(int i = q-1;i>=0;i--){
    if(query[i][0]==1){
      int row = query[i][1]-1;
      lld temp  = table[row][0],temp2;
      for(int i = 1;i<=m;i++){
        temp2 = table[row][i%m];
        table[row][i%m]=temp;
        temp = temp2;
        
      }
    }
    else if(query[i][0]==2){
      int col = query[i][1]-1;
      lld temp = table[0][col],temp2;
      for(int i = 1;i<=n;i++){
        temp2 = table[i%n][col];
        table[i%n][col] = temp;
        temp = temp2;
      }
    }
    else if(query[i][0]==3){
      int row = query[i][1]-1,col = query[i][2]-1;
      table[row][col] = query[i][3];
    }
  
  }
  for(int i = 0;i<n;i++){
    for(int j =0;j<m;j++)
      cout<<table[i][j]<<" ";
      cout<<endl;
  } 
  
}
