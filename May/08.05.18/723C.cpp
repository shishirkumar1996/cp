#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >

using namespace std;


int main(){

  faster
  int n,m;
  cin>>n>>m;
  
  vi input(n);
  for(int i= 0;i<n;i++)
    cin>>input[i];
  
  vi diff(m+1);
  lld change =0;
  
  lld min = n/m;
  
  for(int i = 1;i<=m;i++)
    diff[i]  = -min;

  for(int i = 0;i<n;i++)
    if(input[i]<=m) 
      diff[input[i]] += 1;

  
  for(int i =0;i<n;i++){
    if((input[i]<=m && diff[input[i]] > 0)||(input[i]>m))
      for(int j = 1;j<=m;j++){
        if(diff[j]<0){
          change++;
          if(input[i]<=m)
            diff[input[i]]--;
          input[i] = j;
          diff[input[i]]++;
          break;
        }
      }
  }
  cout<<min<<" "<<change<<endl;
  for(int i= 0;i<n;i++)
    cout<<input[i]<<" ";
  cout<<endl;
  

}
