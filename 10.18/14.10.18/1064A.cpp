#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define pr pair< lld,lld >
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  
  faster
  int a[3];
  cin>>a[0]>>a[1]>>a[2];
  sort(a,a+3);
  
  int ans = 0;
  cout<<max(0,a[2]-a[1]-a[0]+1)<<endl;
  
}
