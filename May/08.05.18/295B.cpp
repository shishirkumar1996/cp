#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
#define vii vector< vi >

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  
  lld input[n+1][n+1];
  
  for(int i = 1;i<=n;i++)
    for(int j = 1;j<=n;j++) cin>>input[i][j];
  
  vi query(n);
  for(int i = 0;i<n;i++) cin>>query[i];

  vi result(n);
  bool included[n+1];
  for(int i = 1;i<=n;i++)
    included[i]  = false;
    
  
  for(int i =n-1;i>=0;i--){
    lld sum = 0;
    included[query[i]] = true;
    for(int j = 1;j<=n;j++)
      for(int k = 1;k<=n;k++){
          input[j][k] = min(input[j][k],input[j][query[i]]+input[query[i]][k]);
          if(included[j]==true && included[k]==true)
            sum = sum+input[j][k];
        
      }
    result[i]  = sum;
  }
  
  for(int i = 0;i<n;i++) cout<<result[i]<<" ";
  cout<<endl;
}
