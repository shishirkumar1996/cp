#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": "; for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  
  int n;
  cin>>n;
  
  vi input(n);
  lld ans = 0;
  for(int i=0;i<n;i++)cin>>input[i];
  
  lld last = input[0];
  lld num = 1;
  for(int i=1;i<n;i++){
    if(input[i]!=last){
      ans += (num*(num+1))/2;
      last = input[i];num = 1;
    } else num++;
  }
  ans += (num*(num+1))/2;
  cout<<ans<<endl;
}
