#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  lld n;
  cin>>n;
  
  lld x= n*(n-1)*(n-2)*(n-3)*(n-4);
  lld y= x/(2*3*4*5);
  
  cout<<x*y<<'\n';
}
