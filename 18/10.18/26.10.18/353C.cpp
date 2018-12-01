#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){

  int n;
  cin>>n;
  vi input(n+1);
  lld sum[n+1];
  sum[0] = 0;
  for(int i=1;i<=n;i++){
    cin>>input[i];
    sum[i] =sum[i-1]+input[i];
  }
  string num;
  cin>>num;
  lld temp = 0;
  lld ans = 0;
  for(int i=n;i>=1;i--){
    if(num[i-1]=='0')continue;
    ans = max(ans,temp+sum[i-1]);
    temp += input[i];
  }
  ans = max(ans,temp);
  cout<<ans<<endl;
}
