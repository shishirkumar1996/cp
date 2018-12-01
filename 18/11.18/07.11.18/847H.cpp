#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(1e18)
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  
  int n;
  cin>>n;
  vi input(n+1);
  for(int i=1;i<=n;i++)cin>>input[i];
  
  lld left[n+1],right[n+1],greater_left[n+1],greater_right[n+1];
  left[1] = 0;greater_left[1] = input[1];
  right[n] = 0;greater_right[n] = input[n];
  
  
  lld ans = MAXM;
  for(int i=2;i<=n;i++){
    lld temp = 0;
    if(input[i]<=greater_left[i-1])temp = (greater_left[i-1]-input[i])+1;
    greater_left[i] = input[i]+temp;
    left[i]  = left[i-1]+temp;
  }
  ans = min(ans,left[n]);
  
  for(int i=n-1;i>=1;i--){
    lld temp = 0;
    if(input[i]<=greater_right[i+1])temp = (greater_right[i+1]-input[i])+1;
    greater_right[i] = input[i]+temp;
    right[i] = right[i+1]+temp;
  }
  ans = min(ans,right[1]);
  for(int i=1;i<n;i++){
    lld temp = left[i]+right[i+1];
    if(greater_left[i]==greater_right[i+1])temp++;
    ans = min(ans,temp);
  }
  cout<<ans<<'\n';
}
