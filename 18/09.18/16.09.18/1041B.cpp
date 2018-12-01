#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

lld gcd(lld a,lld b){ if(b==0)return a;return gcd(b,a%b); }

int main(){
  lld a,b,x,y;
  cin>>a>>b>>x>>y; 
  
  lld g = gcd(x,y);
  x = x/g; y = y/g;

  lld minm = min(a/x,b/y);
  cout<<minm<<endl;  
}
