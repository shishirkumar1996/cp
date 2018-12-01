#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

lld power(lld x,lld y){

  lld res = 1;
  x = x%MOD;
  
  while(y>0){
    if( y&1) res = (res*x)%MOD;
    
    y = y>>1;
    x = (x*x)%MOD;
  }
  return res;
}

int main(){

  int n,q;
  cin>>n>>q;
  string input;
  cin>>input;
  int sum[input.length()+1];
  sum[0] = 0;
  for(int i=1;i<=n;i++){
    sum[i] = sum[i-1];
    if(input[i-1]=='1')sum[i]++;
  }  
  
  while(q--){
    int l,r;
    cin>>l>>r;
    int x = sum[r]-sum[l-1];
    int num = r-l+1;
    lld ans = (power(2,x)-1)%MOD;
    int y = num-x;
    lld ans2 = (ans*(power(2,y)-1))%MOD;
    ans += ans2;
    ans %= MOD;
    cout<<ans<<endl;
  }

}
