#include<bits/stdc++.h>
#define lld long long int

using namespace std;

lld pascal[31][31];


void calcpascal(){

  for(int i = 0;i<=30;i++)
    for(int j = 0;j<=i;j++)
      if(j==0 || j== i)
        pascal[i][j] = 1;
      else
        pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
  

}

lld calc(int n,int m,int k){

  lld result = 0;
  for(int i = max(k-m,4);i<=min(n,k-1);i++){
    result += pascal[n][i] * pascal[m][k-i];
//    cout<<result<<endl;
  }

  return result;

}
int main(){
  
  ios::sync_with_stdio(false);
  calcpascal();
  int n,m,k;
  cin>>n>>m>>k;
  
  cout<<calc(n,m,k)<<endl;

}

