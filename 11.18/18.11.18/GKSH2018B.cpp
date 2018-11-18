#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vs vector< string >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }
#define NUM 5000007

using namespace std;

lld sum[NUM];

int main(){

  int t;
  cin>>t;
  for(int x=1;x<=t;x++){
    lld n;
    cin>>n;
    string input;
    cin>>input;
    lld l = (n+1)/2;
    lld ans = 0;
    sum[0] = 0;
    for(lld i=1;i<=n;i++) sum[i] = sum[i-1]+(input[i-1]-'0');
    for(lld i=1;i<=n;i++){
      ans = max(ans,sum[min(n,i+l-1)]-sum[i-1]);
    }
    cout<<"Case #"<<x<<": "<<ans<<'\n';
  }
}
