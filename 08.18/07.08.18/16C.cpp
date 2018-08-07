#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

lld gcd(lld a,lld b){
  if(a%b==0)return b;
  return gcd(b,a%b);
}

int main(){

  lld a,b,x,y;
  cin>>a>>b>>x>>y;
  lld g = gcd(x,y);
  x = x/g,y=y/g;
  if(a<x || b<y){cout<<0<<" "<<0<<endl;return 0;}
  
  lld low = 1,high = 2e9+7;
  lld rat=1;
  while(low<=high){
    lld mid = (low+high)/2;
    if(x*mid>a || y*mid>b) high = mid-1;
    else{rat=mid;low=mid+1;}
  }
  cout<<rat*x<<" "<<rat*y<<endl;
}
