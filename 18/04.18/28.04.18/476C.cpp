#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define mod (lld)(1e9+7)

using namespace std;


lld calc(lld a,lld b){
  
  lld ans = 0;
  lld b_part = ((b*(b-1))/2)%mod;
  lld a_part = ((a*(a+1))/2)%mod;
  lld first = (a_part*b_part)%mod;
  first = (first*b)%mod;
  
  lld second = 0;
  second = (b_part*a)%mod;
//  cout<<first<<" "<<second<<endl;  
  ans = (first+second)%mod;
    
  return ans;

}

int main(){

  faster
  lld a,b;
  cin>>a>>b;
  cout<<calc(a,b)<<endl;

}
