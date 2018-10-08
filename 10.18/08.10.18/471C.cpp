#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){

  lld n;
  cin>>n;
  
  lld temp = 0;
  lld h = 0;
  while(temp<=n){ temp += 3*h+2;h++; } 
  h--;
  lld ans;
  if(n%3==0)ans = h/3;
  else if(n%3==1) ans = (h+1)/3;
  else if(n%3==2) ans = (h+2)/3;
  cout<<ans<<endl;
}
