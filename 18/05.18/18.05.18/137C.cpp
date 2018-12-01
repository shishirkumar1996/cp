#include<bits/stdc++.h>
#define lld long long int
#define pr pair< lld ,lld >
#define vp vector< pr >
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  vp input(n);
  for(int i = 0;i<n;i++) cin>>input[i].first>>input[i].second;
  
  sort(input.begin(),input.end());
  
  int ans =0;
  lld left = input[0].first,right = input[0].second;
  for(int i = 1;i<n;i++){
    if(input[i].first > left && input[i].second <  right) ans++;
    if(input[i].second > right) left = input[i].first , right = input[i].second;
  }
  cout<<ans<<endl;

}  
