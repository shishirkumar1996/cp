#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++) cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

bool diff(lld n,lld s){
  lld temp = n;
  lld x= 0;
  while(temp){ x += temp%10; temp = temp/10;}
  return (n-x>=s);
}

int main(){

  lld n,s;
  cin>>n>>s;
  lld l = 1,r = (lld)(n+7ll);
  while(l<r){
    lld mid = l +(r-l)/2ll;
    if(diff(mid,s)) r = mid; else l = mid+1;
  }
  cout<<max(n-l+1,0ll)<<endl;
}
