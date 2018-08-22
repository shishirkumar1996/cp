#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  lld x;
  cin>>x;
  if(x<0) x = -x;
  
  lld n=0;
  while(((n+1)*(n+2))/2<=x) n++;
  cout<<n+2*(x-(n*(n+1))/2)<<endl;
}
