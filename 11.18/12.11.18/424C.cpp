#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  int n;
  cin>>n;
  
  int pre[n];
  int sum[n+1];
  pre[0] = 0;
  for(int i=1;i<n;i++)pre[i] = pre[i-1]^i;
  
  int ans = 0;  
  for(int i=1;i<=n;i++){
    int x = n/i;
    int y = n%i;
    if(x%2==0) sum[i] = pre[y];
    else sum[i] = pre[i-1]^pre[y];
    ans = ans^sum[i];
  }
  
  vi input(n);
  for(int i=0;i<n;i++){ cin>>input[i]; ans ^= input[i]; }
  cout<<ans<<endl;
    
}
