#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >

using namespace std;

int main(){

  faster
  int n,m;
  cin>>n>>m;
  
  vi city(n),tower(m);
  for(int i = 0;i<n;i++)  cin>>city[i];
  for(int i = 0;i<m;i++)  cin>>tower[i];
  
  lld minm = 0;
  for(int i = 0;i<n;i++){
    lld sol = INT_MAX;
    int index = upper_bound(tower.begin(),tower.end(),city[i])-tower.begin();
    if(index > 0)
      sol = min(sol,abs(tower[index-1]-city[i]));
    if(index < m)
      sol = min(sol,abs(tower[index]-city[i]));
    minm = max(sol,minm);
  }
  cout<<minm<<endl;
}
