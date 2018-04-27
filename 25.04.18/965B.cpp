#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vc vector< char >
#define vcc vector< vc >

using namespace std;

void calc(int n,int k,vcc input){

  int output[n][n];
  int max_row = 1,max_col = 1,maxm = 0;
  for(int i= 0;i<n;i++){
    for(int j = 0;j<n;j++){
      output[i][j] = 0;
      if(input[i][j]=='#')
        continue;
      
      int sum = 1;
      for(int l = j-1;l>=max(0,j-k+1);l--)
        if(input[i][l] == '#')
          break;
        else
          sum++; 
      for(int l = j+1;l<=min(n-1,j+k-1);l++)
        if(input[i][l]=='#')
          break;
        else
          sum++;
      
      output[i][j] += max(0,sum-k+1);
      
      sum = 1;
      for(int l = i-1;l>=max(0,i-k+1);l--)
        if(input[l][j] == '#')
          break;
        else
          sum++; 
      for(int l = i+1;l<=min(n-1,i+k-1);l++)
        if(input[l][j]=='#')
          break;
        else
          sum++;
      
      output[i][j] += max(0,sum-k+1); 
    
//      cout<<i<<" "<<j<<" "<<output[i][j]<<endl;
      if(maxm < output[i][j])
        maxm = output[i][j],max_row = i+1,max_col = j+1;
    
    }
   
  
  }
  
  cout<<max_row<<" "<<max_col<<endl; 

}


int main(){

  int n,k;
  cin>>n>>k;
  vcc input(n);
  for(int i =0;i<n;i++)
    for(int j = 0;j<n;j++){
      char ct;
      cin>>ct;
      input[i].push_back(ct);
    }
  
    
  calc(n,k,input); 
  


}
