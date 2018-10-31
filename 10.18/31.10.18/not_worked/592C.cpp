#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

lld gcd(lld a,lld b){
  if(b==0)return a;
  return gcd(b,a%b);
}

int main(){
  lld t,w,b;
  cin>>t>>w>>b;
  
  lld lcm = w/gcd(w,b)*b;
  lld num = min(w,b)*(1ll+t/lcm);
  num -= max(0ll,min(w,b)-1ll-t%lcm);
  num -= 1;
  lld g = gcd(num,t);
  cout<<num/g<<'/'<<t/g<<'\n';
}
