#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);
#define lld long long int
#define vi vector< lld >

using namespace std;

int main(){

  faster
  int h;
  cin>>h;
  vi  input(h+1);
  vi sum(h+1);
  
  for(int i = 0;i<=h;i++){
    cin>>input[i];
    sum[i] = (i==0)?input[i]:sum[i-1]+input[i];
  }  
  
  int flag = 1;
  for(int i = 1;i<=h;i++)
    if(input[i] > 1 && input[i-1] > 1){
      flag = 0;
      break;
    }  
  
  if(flag){
    cout<<"perfect"<<endl;
    return 0;
  }
  else {
    int first[sum[h]],second[sum[h]];
    memset(first,0,sizeof(first));
    memset(second,0,sizeof(second));  
     
    for(int i = 1;i<=h;i++){
        
      for(int j = 0;j<input[i];j++){
        first[sum[i-1]+j] = (i>=2)?sum[i-2]+1:1;
        
        if(j==0)
          second[sum[i-1]+j] = (i>=2)?sum[i-2]+1:1;
        else{
          if(i>=2){
            if(input[i-1]>1)
              second[sum[i-1]+j] = sum[i-2]+2;
            else
              second[sum[i-1]+j] = sum[i-2]+1;
          }
          else
            second[sum[i-1]+j] = 0+1;
        }  
      }
    
    }
    cout<<"ambiguous"<<endl;
    for(int i=0;i<sum[h];i++)
      cout<<first[i]<<" ";
    cout<<endl;
    for(int i = 0;i<sum[h];i++)
      cout<<second[i]<<" ";
    cout<<endl;
  }
}
