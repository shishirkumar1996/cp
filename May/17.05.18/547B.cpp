#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
#define pr pair< lld, lld >
#define vp vector< pr >

using namespace std;


int compare(pr a,pr b){
  
  return (a.first < b.first || (a.first == b.first && a.second > b.second));
}

int main(){
  
  faster
  lld n;
  cin>>n;
  vi input(n+1);
  for(int i = 1;i<=n;i++) cin>>input[i];
  stack< lld > process;
  
  lld left[n+1],right[n+1];
  
  for(int i = 1;i<=n;i++){
    
    while(process.size() && input[process.top()] >= input[i])
      process.pop();
    if(process.size())
      left[i] = process.top()+1;
    else
      left[i] = 1;
    process.push(i); 
  
  }
  while(process.size()) process.pop();
  
  for(int i = n;i>=1;i--){
    while(process.size() && input[process.top()] >= input[i])
      process.pop();
      
    if(process.size())
      right[i] = process.top()-1;
    else
      right[i] = n;
    process.push(i);
  }

  lld answer[n+2];
  for(int i = 0;i<=n+1;i++) answer[i] = 0;

  for(int i = 1;i<=n;i++){
    lld len = right[i] -left[i]+1;
    answer[len] = max(answer[len],input[i]);
  }
  
  for(int i = n;i>=1;i--)
    answer[i] = max(answer[i],answer[i+1]);
  
  for(int i = 1;i<=n;i++)
    cout<<answer[i]<<" ";
  cout<<endl;
}
