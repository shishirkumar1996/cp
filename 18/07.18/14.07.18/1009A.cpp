#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  int n,m;
  cin>>n>>m;
  vi games(n),wallet(m);
  for(int i=0;i<n;i++)cin>>games[i];
  for(int i=0;i<m;i++)cin>>wallet[i];
  
  int ans = 0;
  int j=0;
  for(int i=0;i<n&&j<m;i++){
    if(games[i]<=wallet[j]){ans++;j++;}
  }
  cout<<ans<<endl;

}
