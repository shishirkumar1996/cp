#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){

  int m,k;
  cin>>m>>k;
  vi distance(m),cap(m);
  for(int i=0;i<m;i++)cin>>distance[i];
  for(int i=0;i<m;i++)cin>>cap[i];
  
  int maxm = 0;
  int ans = 0;
  int fuel = 0;
  for(int i=0;i<m;i++){
    maxm = max(maxm,cap[i]);
    fuel += cap[i];
    while(fuel<distance[i]){ ans += k;fuel += maxm; }
    fuel -= distance[i];
    ans += distance[i];
  }
  cout<<ans<<endl;
}
