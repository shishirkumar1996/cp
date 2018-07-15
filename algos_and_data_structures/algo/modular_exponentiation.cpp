#include<bits/stdc++.h>
#define MOD (lld)(1e9+7)
#define lld long long int

using namespace std;


lld power(lld x, lld y){

  lld res = 1;
  x = x%MOD;
  
  while(y>0){
    if( y&1) res = (res*x)%MOD;
    
    y = y>>1;
    x = (x*x)%MOD;
  }
  return res;
}

int main(){
  
  lld x,y;
  cin>>x>>y;
  cout<<power(x,y)<<endl;
}
