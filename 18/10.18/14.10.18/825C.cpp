#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
  
  lld n,k;
  cin>>n>>k;
  
  vi input(n);
  for(int i=0;i<n;i++) cin>>input[i];

  sort(input.begin(),input.end());
  lld ans = 0;
  for(int i=0;i<n;i++){
    while((input[i]+1)/2>k){k=k*2;ans++;}
    if((input[i]+1)/2<=k)k=max(k,input[i]);
  }
  cout<<ans<<endl;
}
