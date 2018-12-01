#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define faster ios_base::sync_with_stdio(false);


using namespace std;

int main(){
  int num[4];
  for(int i = 0;i<4;i++) cin>>num[i];
  
  int r = 36,c = 50;
  char ans[r][c];
  
  for(int i = 0;i<4;i++){
    char first = 'A'+i,second = 'A'+(i+1)%4;    
    for(int j = i*9;j<(i+1)*9;j++) for(int k = 0;k<50;k++) ans[j][k] = first;
    int row = i*9+1,col = 0;
    int x= num[(i+1)%4]-1;
    for(int j=0;j<x;j++){
      ans[row][col] = second;
      col += 2;
      if(col>=50) col=0,row+=2;
    }  
  }
  cout<<r<<" "<<c<<endl;
  for(int i = 0;i<r;i++){
    for(int j = 0;j<c;j++)cout<<ans[i][j];
    cout<<endl;
  }
}
