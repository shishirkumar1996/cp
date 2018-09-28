#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  lld v[n+1],d[n+1],p[n+1];
  for(int i = 1;i<=n;i++) cin>>v[i]>>d[i]>>p[i];
  vi output;
  int index = 1;
  while(index<=n){
    
    if(p[index]<0){
      for(int i = index+1;i<=n;i++) if(p[i]>=0)p[i] -= d[index];
      index++;
    }
    else{
      output.push_back(index);
      int temp = index+1;
      int x = 0;
      while(x<v[index] && temp<=n){
        if(p[temp]>=0){ p[temp] -= (v[index]-x);x++; }
        temp++;
      }
      index++;
    }  
  
  }
  cout<<output.size()<<endl;
  for(int i =0;i<output.size();i++)cout<<output[i]<<" ";
  cout<<endl;
  
}
