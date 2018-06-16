#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >

using namespace std;


int main(){

  faster
  lld n,k,l;
  cin>>n>>k>>l;
  vi input(n*k);
  
  for(int i = 0;i<n*k;i++) cin>>input[i];
  
  sort(input.begin(),input.end());
  
  lld an = 0;
  vi ans(n);
  
  for(int i = 0;i<n;i++) ans[i] = i;

  int flag = 1;
  lld ind = upper_bound(input.begin(),input.end(),input[0]+l)-input.begin();
  ind--;
  for(int i = n-1;i>=0;i--){
    
    if(input[ans[i]]-input[0]>l){flag = 0;break;}
    
    ans[i] = min(ind-(n-1-i),(n*k)-k-(n-1-i)*k);
//    cout<<i<<" "<<ans[i]<<" "<<input[ans[i]]<<endl;
  }
  if(!flag){
    cout<<0<<endl;
    return 0;
  }

  for(int i =0;i<n;i++) an += input[ans[i]];
  cout<<an<<endl;
}
