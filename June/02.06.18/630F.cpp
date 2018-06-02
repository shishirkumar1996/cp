#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
  
  faster
  int n;
  cin>>n;
  
  lld sum = 0;
  lld mul = 1;
  for(int i = 1;i<=4;i++) mul = mul*(n-i+1);
  
  for(int i = 1;i<=4;i++) mul = mul/i;
  
  for(int i = 5;i<=7;i++){
    mul = mul*(n-i+1);
    mul = mul/i;
    sum += mul;
  }
  cout<<sum<<endl;
  
}
