#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  lld n,k;
  cin>>n>>k;
  
  lld maxm,minm;
  if(2*n-1<k){cout<<0<<endl;return 0;}
  
  if(k-1<=n){ maxm = k-1;minm = 1;}
  else {maxm = n;minm = k-n; }
//  cout<<minm<<" "<<maxm<<endl;
  lld ans = maxm-minm+1;
  if(k%2==0)ans--;
  ans = ans/2;
  cout<<ans<<endl;
}
