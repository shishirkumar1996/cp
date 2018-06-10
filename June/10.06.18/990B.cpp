#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
  
  faster
  lld n,k;
  cin>>n>>k;
  vi input(n);
  for(int i = 0;i<n;i++)cin>>input[i];
  
  sort(input.begin(),input.end());
  lld ans = n;
  for(int i = 0;i<n;i++){
    int index = upper_bound(input.begin(),input.end(),input[i]+k)-input.begin()-1;
    if(input[index] != input[i]) ans--;
  }
 
  cout<<ans<<endl; 
}
