#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);


using namespace std;

int main(){
  int n;
  cin>>n;  
  
  int output[n][n];
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)output[i][j] = 0;
  
  int num = 1;
  for(int i=0;i<n;i++)
    if(i==n/2)continue;
    else{
      output[n/2][i] = num;
      output[i][n/2] = num+2;
      num += 4;
    }
    
  output[n/2][n/2] = num;num+=2;
  
  int r = 0,c = 0;
  while(num<=n*n){
    output[r][c] = num;
    output[n-r-1][c] = num+2;
    output[r][n-c-1] = num+4;
    output[n-r-1][n-c-1] = num+6;
    num += 8;
    c+=1;
    if(c==n/2){ c = 0;r++; }
  }
  num = 2;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)if(!output[i][j]){ output[i][j] = num; num+=2; }
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)cout<<output[i][j]<<" ";
    cout<<'\n';
  }
}
