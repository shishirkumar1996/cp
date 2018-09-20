#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  lld l,r;
  cin>>l>>r;
  cout<<"YES"<<endl;
  for(lld i=l;i<=r;i+=2)cout<<i<<" "<<(i+1)<<'\n';

}
