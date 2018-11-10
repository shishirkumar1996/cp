#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  faster
  lld n,m,l;
  cin>>n>>m>>l;
  
  vi input(n);
  int ans = 0;
  for(int i=0;i<n;i++){
    cin>>input[i];
    if(input[i]>l&&(i==0||input[i-1]<=l)) ans++;
  }
  while(m--){
    int t;
    cin>>t;
    if(t==0)cout<<ans<<'\n';
    else{
      lld p,d;
      cin>>p>>d;
      p--;
      if(input[p]>l){ input[p] += d; continue; }
      input[p] += d;
      if(input[p]<=l)continue;
      if(p>0 && p<n-1 && input[p-1]>l && input[p+1]>l)ans--;
      else if(!(p>0 && input[p-1]>l) && !(p<n-1 && input[p+1]>l))ans++;
    }
  }
}
