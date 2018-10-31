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

  vi input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  map< int,int > temp[n];
  temp[0][0] = 1;
  int maxm = 1;
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      int diff = input[i]-input[j];
      temp[i][diff] = max(max(2,temp[j][-diff]+1),temp[i][diff]);
      maxm = max(maxm,temp[i][diff]);
//      cout<<i<<" "<<j<<" "<<diff<<" "<<temp[i][diff]<<'\n';
    }
  }
  cout<<maxm<<'\n';
}
