#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  faster
  lld n,k;
  cin>>n>>k;
  
  if(k>(lld)(1e6)){cout<<-1<<endl;return 0;}
  lld div = -1;
  for(lld i=1;i<=sqrt(n);i++){
    if(n%i != 0) continue;
    lld sum = n/i;
    if(sum >= (k*(k+1))/2) div = max(div,i);
    sum = n/(n/i);
    if(sum >=(k*(k+1))/2)div = max(div,n/i);
  }
  if(div==-1){cout<<-1<<endl;return 0;}
  lld temp = n/div;
  vector< lld > ans;
  lld index = temp;
  lld num = k;
  while(temp && num){
    index = temp-(num*(num-1))/2;
    ans.push_back(div*index);temp -= index;num--;
  }
  reverse(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
  cout<<endl;
}
