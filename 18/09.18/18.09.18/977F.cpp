#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< int >

using namespace std;

int main(){
  faster
  int n;
  cin>>n;
  
  vi input(n);
  for(int i = 0;i<n;i++) cin>>input[i];
  
  map< lld,lld > process;
  for(int i=0;i<n;i++)
    process[input[i]] = max(process[input[i]],process[input[i]-1]+1);
  
  lld maxm = 0,index;
  for(int i=0;i<n;i++)
    if(maxm<process[input[i]]){
      maxm = process[input[i]];
      index =i;
    }
  
  cout<<maxm<<endl;
  lld num = input[index]-maxm+1;
  for(int i=0;i<n;i++)
    if(num==input[i]){ cout<<i+1<<" "; num++; }
  cout<<endl;
  
}
