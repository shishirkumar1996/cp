#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  lld n;
  cin>>n;
  lld ans = 0;
  for(lld i=2;i<=n/2;i++){
    lld x = (n-i)/i;
    ans += 4*x*i;
  }
  cout<<ans<<'\n';
}
