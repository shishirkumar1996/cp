#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

lld gcd(lld a,lld b){
  if(b==0)return a;
  return gcd(b,a%b);
}

int main(){
  
  int n;
  cin>>n;
  vi input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  lld g = input[0];
  for(int i=1;i<n;i++)g = gcd(g,input[i]);
  if(g>1){cout<<"YES"<<endl<<0<<endl;return 0;}
  
  int ans = 0;
  for(int i=0;i<n;i++){
    if(input[i]%2==0)continue;
    if(i==n-1||(input[i+1]%2==0)){
      cout<<"NO"<<endl;return 0;
    }
    lld x = input[i]-input[i+1];
    lld y =input[i]+input[i+1];
    input[i] = x,input[i+1] = y;
    ans++;
  }
  cout<<"YES\n"<<ans<<endl;
}
