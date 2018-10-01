#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  vi input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  sort(input.begin(),input.end());
  reverse(input.begin(),input.end());
  
  lld sum[n+1];
  sum[0] = 0;
  for(int i=1;i<=n;i++)sum[i] = sum[i-1]+input[i-1];
  
  lld ans = 0;
  for(int i=1;i<=n;i*=4)ans += sum[i];
  cout<<ans<<endl;
}
