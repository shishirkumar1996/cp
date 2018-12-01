#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  int n;
  cin>>n;
  
  vi input(n);
  lld sum = 0;
  for(int i=0;i<n;i++){ cin>>input[i];sum+= input[i]; }
  lld num = sum/n;
  lld x = n-sum%n;
  
  lld ans = 0;
  sort(input.begin(),input.end());
  for(int i=0;i<n;i++){
    lld y;
    if(i<x) y = num; else y = num+1;
    if(y-input[i]<=0)continue;
    ans+= (y-input[i]);
  }
  cout<<ans<<endl;

}

