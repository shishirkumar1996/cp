#include<bits/stdc++.h>
#define lld long long int

using namespace std;

lld choose(lld n,lld p){
  lld ans = 1;
  if(n==p)return 1;
  p = min(p,n-p);
  for(int i=n;i>n-p;i--)ans= ans*i;
  for(int i=1;i<=p;i++)ans = ans/i;
  return ans;
}

int main(){
  
  lld n,k;
  cin>>n>>k;
  int derange[5]; //number of ways to store derangement
  derange[1] = 0;
  derange[0] = 1;
  derange[2] = 1;
  derange[3] = 2*(derange[2]+derange[1]);
  derange[4] = 3*(derange[3]+derange[2]);
  
  lld ans = 1;
  for(int i=2;i<=k;i++)ans = ans+choose(n,i)*derange[i];

  cout<<ans<<endl;
}
