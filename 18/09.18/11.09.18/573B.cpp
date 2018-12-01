#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  int n;
  cin>>n;
  vi input(n+1);
  for(int i=1;i<=n;i++)cin>>input[i];
  
  lld time[n+1];
  time[1] = 1;
  time[n] = 1;
  lld maxm = 1;
  for(int i=2;i<=n-1;i++) time[i] = min((lld)i,min(input[i],time[i-1]+1));
  for(int i=n-1;i>=1;i--) time[i] = min(time[i],min((lld)(n-i+1),time[i+1]+1));
  
  for(int i=1;i<=n;i++)maxm = max(maxm,time[i]);
  cout<<maxm<<endl;
}
