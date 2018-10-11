#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  faster
  int t;
  cin>>t;
  while(t--){
    lld s,a,b,c;
    cin>>s>>a>>b>>c;
    lld ans =0;
    ans = (s/(a*c))*(a+b);
    s = s%(a*c);
    ans += s/c;
    cout<<ans<<endl;
  }

}
