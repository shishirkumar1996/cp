#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int level[201][201];
  for(int i=0;i<201;i++)for(int j=0;j<201;j++)level[i][j] = INT_MAX;
  
  string input;
  cin>>input;
  level[100][100] = 0;
  int row = 100,col = 100;
  
  for(int i=0;i<input.size();i++){
    level[row][col+1] = min(level[row][col]+1,level[row][col+1]);
    level[row][col-1] = min(level[row][col]+1,level[row][col-1]);
    level[row-1][col] = min(level[row][col]+1,level[row-1][col]);
    level[row+1][col] = min(level[row][col]+1,level[row+1][col]);
    
    int new_row=row,new_col=col;
    if(input[i]=='L')new_col--;
    else if(input[i]=='R') new_col++;
    else if(input[i]=='U') new_row--;
    else if(input[i]=='D') new_row++;
    if(level[new_row][new_col]<level[row][col]+1){cout<<"BUG"<<endl;return 0;}
    row = new_row,col = new_col;
  }
  cout<<"OK"<<endl;
}
