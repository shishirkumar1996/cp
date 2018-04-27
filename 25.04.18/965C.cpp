#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int


using namespace std;


lld calc(lld n,lld k,lld m,lld d){

  lld maxm = 0;

  for(lld i = 1;i<=d;i++){
    
    lld val =k*(i-1)+1;
    if(val > n | val <= 0)
      break;
    lld a = min(m,n/val);
    lld ans = a*i;
    maxm = max(maxm,ans);
  }

  return maxm;
}


int main(){
  
  faster
  lld n,k,m,d;
  cin>>n>>k>>m>>d;
  cout<<calc(n,k,m,d)<<endl;


}
