#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)1e20+7

using namespace std;


int main(){

  int n;
  cin>>n;
  vi input(2*n);
  for(int i=0;i<2*n;i++)cin>>input[i];
  
  sort(input.begin(),input.end());
  
  lld ans = (input[n-1]-input[0])*(input[2*n-1]-input[n]);
  for(int i=1;i<n;i++)
    ans = min(ans,(input[i+n-1]-input[i])*(input[2*n-1]-input[0]));
  
  cout<<ans<<endl;
}
