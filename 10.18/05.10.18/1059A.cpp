#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){

  int n;lld l,a;
  cin>>n>>l>>a;
  
  lld ans = 0;
  lld last = 0;
  for(int i=0;i<n;i++){
    lld x,y;
    cin>>x>>y;
    ans += (x-last)/a;
    last = x+y;
  }
  ans += (l-last)/a;
  cout<<ans<<endl;
}
