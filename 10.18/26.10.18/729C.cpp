#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(1e10)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

lld n,k,s,t;
bool check(lld v,vi gas){
  lld temp = 0;
  for(int i = 1;i<gas.size();i++){
    lld dist = gas[i]-gas[i-1];
    lld dbl = v-dist;
    if(dbl<0)return false;
    dbl = min(dist,dbl);
    temp += dbl+(dist-dbl)*2;
  }
  if(temp<=t)return true;
  return false;
}

int main(){

  faster
  cin>>n>>k>>s>>t;
  
  vi price(n),cap(n);
  for(int i=0;i<n;i++)cin>>price[i]>>cap[i];
  
  vi gas(k);
  gas.push_back(0);
  for(int i=0;i<k;i++){ lld a;cin>>a; gas.push_back(a); }
  gas.push_back(s);
  
  sort(gas.begin(),gas.end());
  
  lld l=1,r = (lld)(1e10);
  
  lld mid;
  while(l<r){
    mid = (l+r)/2;
    if(check(mid,gas))r = mid;
    else l = mid+1;
  }
  lld temp = r;
//  trace(temp);
  lld ans = MAXM;
  for(int i=0;i<cap.size();i++)
    if(temp<=cap[i]) ans = min(ans,price[i]);
  
  if(ans==MAXM)cout<<-1<<endl;
  else cout<<ans<<endl;
}
