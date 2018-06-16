#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

lld hcf(lld a,lld b){
  
  if(a<b)    lld temp =a,a = b,b = temp;
  if(b==0)
    return a;
  else return hcf(b,a%b);
}


int main(){
  lld n,a,b,p,q;
  cin>>n>>a>>b>>p>>q;
  cout<<(n/a)*p+(n/b)*q-(n/((a*b)/hcf(a,b)))*min(p,q)<<endl;
}
