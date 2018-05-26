#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  faster
  int n,R,r;
  cin>>n>>R>>r;
  
  if(n==1){ if(R>=r)cout<<"YES"<<endl; else cout<<"NO"<<endl; return 0;}
  
  double rad = (R-r)*sin(3.1415926/n)+1e-7;
  if(rad>=r) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
