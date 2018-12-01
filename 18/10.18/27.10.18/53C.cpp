#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n;
  cin>>n;
  
  int l = 1,r = n;
  while(l<r) cout<<l++<<" "<<r--<<" ";
  if(l==r)cout<<l;
  cout<<'\n';

}
