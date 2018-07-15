#include<bits/stdc++.h>
#define vi vector< int >

using namespace std;


int main(){

  int n,sum;
  cin>>n>>sum;
  vi input(n);
  for(int i=0;i<n;i++) cin>>input[i];
  
  int ways[sum+1][n];
  for(int i=0;i<n;i++) ways[0][i] = 1;
  
  for(int i=1;i<=sum;i++){
    for(int j=0;j<n;j++){
      int x = (i-input[j]>=0)?ways[i-input[j]][j]:0;
      
      int y = (j>=1)?ways[i][j-1]:0;
      ways[i][j] = x+y;
    }
  }  
  cout<<ways[sum][n-1]<<endl;
}
