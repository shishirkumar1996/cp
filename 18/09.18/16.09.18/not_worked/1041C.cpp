#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define vi vector< lld >
#define pr pair< lld,lld >

using namespace std;


int main(){

  faster
  int n;
  lld m,d;
  cin>>n>>m>>d;
  
  d++;

  set< pr > br;
  for(int i=0;i<n;i++){
    pr x;
    cin>>x.first;
    x.second = i;
    br.insert(x);
  }
  
  int ans[n];
  int t = 1;
  while(br.size()){
    pr start = *br.begin();
    ans[start.second] = t;
    lld time = start.first+d;
    br.erase(br.begin());    
    while(true){
      set< pr >::iterator it = lower_bound(br.begin(),br.end(),make_pair(time,-1ll));
      if(it==br.end())break;
      pr y = *it;
      time = y.first+d;
      ans[y.second] = t;      
      br.erase(it);
    }    
    t++;
  }

  cout<<t-1<<'\n';
  for(int i=0;i<n;i++)cout<<ans[i]<<" ";
  cout<<'\n';
}
