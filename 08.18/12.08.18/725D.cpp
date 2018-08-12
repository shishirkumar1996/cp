#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld,lld >
#define vi vector< lld >
#define vp vector< pr >

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  lld x,y;
  cin>>x>>y;
  
  vp input(n-1);
  for(int i=0;i<n-1;i++)cin>>input[i].first>>input[i].second;
  
  sort(input.begin(),input.end());
  reverse(input.begin(),input.end());
  multiset< lld > process;
  
  int ans = INT_MAX;
  int index = 0;
  while(true){
    while(index<n-1){
      if(x>=input[index].first)break;
      else{
        process.insert(input[index].second-input[index].first+1);
        index++;
      }
    }
    ans = min(ans,(int)process.size()+1);
    if(process.size() && *process.begin()<=x){
      x -= *process.begin();
      process.erase(process.begin());
    } else break;
  }
  cout<<ans<<endl;
}
