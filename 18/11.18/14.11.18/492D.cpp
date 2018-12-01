#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define pr pair< lld,lld >
#define vp vector< pr >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

lld gcd(lld a,lld b){
  if(a%b==0)return b;
  return gcd(b,a%b);
}

int main(){

  lld n,x,y;
  cin>>n>>x>>y;
  
  lld g = gcd(x,y);
  lld lcm = x*y/g;
  
  x = lcm/x, y = lcm/y;
  lcm= lcm/g;
  
  vp process;
  for(lld i=x;i<lcm;i+=x)process.push_back(make_pair(i,0));
  for(lld i=y;i<lcm;i+=y)process.push_back(make_pair(i,1));
  process.push_back(make_pair(lcm,2));
  process.push_back(make_pair(lcm-1,2));
  sort(process.begin(),process.end());
  lld tot = lcm/x+lcm/y;
//  for(int i=0;i<tot;i++)cout<<process[i].first<<" "<<process[i].second<<'\n'; 
   
  while(n--){
    lld a;
    cin>>a;
    
    a = a%tot;
    if(a==0)a += tot;
    lld x = process[a-1].second;
    if(x==0)cout<<"Vanya\n";else if(x==1)cout<<"Vova\n"; else cout<<"Both\n";
  }
}
