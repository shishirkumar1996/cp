#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

bool same(lld x,lld b){
  lld temp = 0;
  lld index = 0;
  while(x){
    lld s = x%10;
    if(s==7||s==4)temp = pow(10,index++)*s+temp;
    x = x/10;
  }
  return temp==b;
}

int main(){

  lld a,b;
  cin>>a>>b;
  for(lld i=a+1;i<=199999;i++)if(same(i,b)){ cout<<i<<'\n';return 0; }
}
