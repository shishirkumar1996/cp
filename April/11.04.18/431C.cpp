#include<bits/stdc++.h>

#define MOD (int)(pow(10,9)+7)
#define lld long long int
using namespace std;



lld calc(int n,int k,int d){
  
  int min = d-1;
  
  lld num_ways[n+1];
  lld num_small_ways[n+1];
  num_ways[0] = 1;
  for(int i = 1;i<=n;i++)
  {
    num_ways[i] = 0;
    for(int j=i-1;j>=0 && j>=i-k;j--)
      num_ways[i] += num_ways[j] , num_ways[i] = num_ways[i]%MOD;
  }
  
  num_small_ways[0] = 1;
  for(int i = 1;i<=n;i++)
  {
    num_small_ways[i] = 0;
    for(int j=i-1;j>=0 && j>=i-min;j--)
      num_small_ways[i] += num_small_ways[j],
      num_small_ways[i] = num_small_ways[i]%MOD;
  }
  
/*  for(int i = 1;i<=n;i++)
    cout<<num_ways[i]<<" ";
  cout<<endl;
  cout<<num_ways[n]<<" "<<num_small_ways[n]<<endl;
*/
  lld diff = (num_ways[n] - num_small_ways[n])%MOD;
  if(diff < 0)
    diff += MOD;
  
  return diff;
  
}

int main(){

  int n,k,d;
  cin>>n>>k>>d;
  cout<<calc(n,k,d)<<endl;

}
