#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
  
  int n,m;
  cin>>n>>m;
  vi input(n);
  lld maxm = INT_MIN,minm = INT_MAX;
  for(int i=0;i<n;i++){ cin>>input[i]; 
    maxm = max(maxm,input[i]);
    minm = min(minm,input[i]);
  }
  lld a,b;
  a = maxm+m;
  
  for(int i=0;i<input.size();i++){
    lld dist = max(maxm-input[i],0ll);
    input[i] += dist;
    m -= dist;  
    if(m<=0) break;
  }
  if(m<=0) b= maxm;
  else{
    b = maxm+(n+m-1)/n;
  }
  cout<<b<<" "<<a<<endl;

}
