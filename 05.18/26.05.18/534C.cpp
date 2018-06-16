#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >

using namespace std;

int main(){

  faster
  lld n,d;
  cin>>n>>d;
  vi input(n);
  lld sum = 0;
  for(int i = 0;i<n;i++){ cin>>input[i];sum+= input[i];}
  
  for(int i = 0;i<n;i++){
  
    lld lower = max(1LL,d+input[i]-sum);
    lld higher = min(input[i],d-n+1);
    cout<<((lower>higher)?input[i]:input[i]-higher+lower-1)<<" ";
  }
  cout<<endl;
}
