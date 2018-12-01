#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld, lld >
#define vp vector< pr >

using namespace std;

int main(){
  int n;
  cin>>n;
  vp input(n);
  for(int i = 0;i<n;i++) cin>>input[i].first>>input[i].second;
  
  lld maxm = max(input[0].first,input[0].second);
  
  for(int i=  1;i<n;i++){
    lld a = max(input[i].first,input[i].second);
    lld b = min(input[i].first,input[i].second);
    if(maxm >= a) maxm = a;
    else if(maxm >= b) maxm = b;
    else {cout<<"NO"<<endl;return 0;}
  }
  cout<<"YES"<<endl;
}
