#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
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
  
  vector< int >ans(n);

  
  int t = 1;
  while(br.size()){
    pr start = *br.begin();
    lld time = start.first;
    while(time<=m){
      set< pr >::iterator it = lower_bound(br.begin(),br.end(),make_pair(time,-1ll));
      if(it==br.end())break;
      pr y = *it;
      time = y.first+d;
      ans[y.second] = t;      
      br.erase(it);
    }    
    t++;
  }

/*
  vector< vector< int > > process;
  vector< pr > input(n);
  for(int i=0;i<n;i++){
    cin>>input[i].first;
    input[i].second = i;
  }
  sort(input.begin(),input.end());
  vector< int > ans(n);
  
  int time = input[0].first;
  lld t = 0;
  lld temp  = 1;
  lld last = -1;
  for(int i=0;i<n;i++){
    if(input[i].first<time+d){ 
      ans[input[i].second] = temp;
      t = max(t,temp); 
    }
    else {
      temp = 1;
      time = input[i].first;
      ans[input[i].second] = temp;
    }
    temp++;
  }
*/
  cout<<t-1<<'\n';
  for(int i=0;i<n;i++)cout<<ans[i]<<" ";
  cout<<'\n';
}
