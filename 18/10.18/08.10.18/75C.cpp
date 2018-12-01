#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';
#define vi vector< lld >

using namespace std;

lld gcd(lld a,lld b){
  
  if(b==0)return a;
  return gcd(b,a%b);  

}

int main(){

  lld a,b;
  cin>>a>>b;
  lld g = gcd(a,b);
  vi process;
  for(int i=1;i<sqrt(g);i++)
    if(g%i==0){
      process.push_back(-i);
      process.push_back(-g/i);
    }
  if(g%(lld)sqrt(g)==0)process.push_back(-sqrt(g));
  sort(process.begin(),process.end());
  
  int n;
  cin>>n;
  while(n--){
    lld a,b;
    cin>>a>>b;  
    int index = lower_bound(process.begin(),process.end(),-b)-process.begin();
    if(index==process.size()||process[index]>-a){ cout<<-1<<'\n';continue; }
    cout<<-process[index]<<'\n';
  }
}
