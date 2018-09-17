#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define pr pair< lld,lld >

using namespace std;

int main(){

  lld n,t;
  cin>>n>>t;
  vi input(n+1);
  for(int i=1;i<=n;i++)cin>>input[i];
  
  vi  process;
  int ans = 0;
  lld sum[n+1];
  sum[0] = 0;
  
  process.push_back(0);
  for(int i=1;i<=n;i++){
    sum[i] = sum[i-1]+input[i];
    int index = lower_bound(process.begin(),process.end(),sum[i]-t+1)-process.begin();
    ans += (i-index);
    process.push_back(sum[i]);
    sort(process.begin(),process.end());
  }
  cout<<ans<<endl;
}
