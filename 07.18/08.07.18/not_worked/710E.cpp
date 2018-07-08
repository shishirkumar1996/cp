#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(1e18+7)
#define pr pair< lld,lld >

using namespace std;

int main(){

  faster
  lld n,x,y;
  cin>>n>>x>>y;
  
  lld val[2*n+1];
  lld total = 2*n;
  for(int i= 0;i<=total;i++) val[i] = MAXM;
  
  val[0] = 0;
  stack< lld > process;
  process.push(0);
  
  while(process.size()){
  
    lld top = process.top();
    process.pop();
    if(top+1<=total && val[top+1]> val[top]+x){
      val[top+1] = val[top]+x;
      process.push(top+1);
    }
    if(top-1>=0 && top-1<=total && val[top-1]>val[top]+x){
      val[top-1] = val[top]+x;
      process.push(top-1);
    }
    if(top*2<=total && val[2*top]>val[top]+y){
      val[2*top] = val[top]+y;
      process.push(top*2);
    }
  }
  cout<<val[n]<<endl;
}
