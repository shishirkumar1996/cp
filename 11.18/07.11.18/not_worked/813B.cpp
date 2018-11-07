#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define MAXM (lld)(2e18)
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){

  lld x,y,l,r;
  cin>>x>>y>>l>>r;
  
  vi m,n;
  lld num = 1;
  while(num<=r){ m.push_back(num);num *= x;}
  num = 1;
  while(num<=r){n.push_back(num);num *= y;}
  
  set< lld > process;
  for(int i=0;i<m.size();i++)
    for(int j=0;j<n.size();j++) 
      if(m[i]+n[j]<=MAXM) process.insert(m[i]+n[j]);

  set< lld >::iterator it;
  for( it = process.begin();it!=process.end();it++)cout<<*it<<" ";
  cout<<'\n';

  lld ans = 0;
  lld index = l-1;
  while(index<r){
    lld y = *upper_bound(process.begin(),process.end(),index);
    if(y>r) ans = max(ans,r-index); else ans = max(ans,y-index-1);
//    cout<<ans<<" "<<y<<endl;
    index = y;
  }  
  cout<<ans<<endl;
}
