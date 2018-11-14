#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

int main(){

  lld n;
  cin>>n;
  
  lld temp = n;
  int num = 0,maxm = 0;
  map< lld, int > process;
  lld ans = 1;
  if(n%2==0){
    while(n%2==0)n = n/2,num++;
    maxm = max(maxm,num);
    ans = ans*2;
  }
  
  lld i = 3;
  while(n>1){
    if(n%i==0){
      num = 0;
      while(n%i==0)n=n/i,num++;
      maxm = max(maxm,num);
      ans = ans*i;
    }
    i+=2;
  }
  lld x = 1,y = 0;
  while(x<maxm){ x=2*x; y++; }
  lld output = y;
  x = ans;
  while(x<temp)x *= x;
  if(x>temp )output++;
  cout<<ans<<" "<<output<<'\n';
  
}
