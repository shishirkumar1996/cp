#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  vi input(n);
  for(int i = 0;i<n;i++) cin>>input[i];
  
  lld count = 0;
  
  for(int i = 0;i<n;i++) count += 1+(input[i]-1)*(i+1);
  cout<<count<<endl;

}
