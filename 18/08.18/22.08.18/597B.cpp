#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld,lld >
#define vp vector< pr >

using namespace std;

int compare(pr a,pr b){
  
  return (a.second<b.second)||(a.second==b.second && a.first<b.first);
}

int main(){
  
  faster
  int n;
  cin>>n;
  
  vp input(n);
  for(int i=0;i<n;i++)cin>>input[i].first>>input[i].second;
  
  sort(input.begin(),input.end(),compare);
  int ans = 0;
  lld end = 0;
  for(int i=0;i<n;i++)
    if(input[i].first>end){ ans++; end = input[i].second; }
  
  cout<<ans<<endl;
  
}
