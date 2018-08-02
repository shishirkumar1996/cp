#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int w,h;
  cin>>w>>h;
  
  lld ans = 0;
  
  for(int i=2;i<=w;i+=2)
    for(int j=2;j<=h;j+=2)
      ans += (w-i+1)*(h-j+1);
  
  cout<<ans<<endl;
}
