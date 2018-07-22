#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int N;
void printSolution(vii board){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)cout<<board[i][j]<<" ";
    cout<<endl;
  }
}

bool isSafe(vii board,int row, int col){
  int i,j;
  for(i=0;i<col;i++) if(board[row][i]) return false;
  
  for(i=row,j=col;i>=0 && j>=0;i--,j--) if(board[i][j]) return false;
  for(i=row,j=col;j>=0 && i<N;i++,j--) if(board[i][j]) return false;
  
  return true;
}

int  solveNQ(vii board, int col){
  if(col>=N) return 1;
  
  int num = 0;  
  for(int i=0;i<N;i++)
    if(isSafe(board,i,col)){
      board[i][col] = 1;
      num = num+solveNQ(board,col+1);
      board[i][col] = 0;
    }  
  return num;
}

int main(){

  cout<<"Enter the size of chessboard"<<endl;
  cin>>N;
  vii board(N);
  for(int i=0;i<N;i++)for(int j=0;j<N;j++) board[i].push_back(0);
  cout<<solveNQ(board,0)<<endl;

}
