#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;


int main(){

  int n;
  lld w;
  cin>>n>>w;
  
  lld maxm  = -(lld)(1e9+7), minm = (lld)(1e9+7);
  lld counter = 0;
  for(int i=0;i<n;i++){
    lld a;
    cin>>a;
    counter += a;
    maxm = max(maxm,counter);
    minm = min(minm,counter);
  }
  if(maxm>w || minm<-w){cout<<0<<endl;return 0;}
  lld a = min(w-maxm,w);
  lld b = max(0ll,-minm);
  if(a<b){ cout<<0<<endl; return 0; }
  cout<<a-b+1<<endl;
}
