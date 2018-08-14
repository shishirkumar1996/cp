#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define MAXM (lld)(2e18)
#define vi vector< lld >

using namespace std;

int main(){

  lld x,y,l,r;
  cin>>x>>y>>l>>r;
  
  vi m,n;
  int a= 0;
  while(pow(x,a)<=MAXM){ m.push_back((lld)pow(x,a));a++;}
  a =0 ;
  while(pow(y,a)<=MAXM){n.push_back((lld)pow(y,a));a++;}
  
  set< lld > process;
  for(int i=0;i<m.size();i++)
    for(int j=0;j<n.size();j++) 
      if(m[i]+n[j]<=MAXM) process.insert(m[i]+n[j]);

//  set< lld >::iterator it;
//  for(it = process.begin();it != process.end();it++)cout<<*it<<" ";
//  cout<<endl;

  lld ans = 0;
  lld index = l;
  if(*lower_bound(process.begin(),process.end(),index)==index)index--;  
  while(index<r){
    lld y = *upper_bound(process.begin(),process.end(),index);
    if(y>r) ans = max(ans,r-index); else ans = max(ans,y-index-1);
//    cout<<ans<<" "<<y<<" "<<r<<endl;
    index = y;
  }  
  cout<<ans<<endl;
}
