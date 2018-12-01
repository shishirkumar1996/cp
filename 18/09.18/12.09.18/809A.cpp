#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define MOD (lld)(1e9+7)
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

lld power(lld a,lld x){

  lld y = a;
  lld ans = 1;
  while(x){
    if(x%2==1) ans = (ans*y)%MOD;
    x = x/2;
    y = (y*y)%MOD;
  }
  return ans;
}



int main(){

  faster
  int n;
  cin>>n;
  vi input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  sort(input.begin(),input.end());
  lld ans = 0;
  for(int i=0;i<n;i++){
    ans = (ans+input[i]*(power(2,i)-power(2,n-i-1)))%MOD;
  }
  cout<<ans<<endl;
}
