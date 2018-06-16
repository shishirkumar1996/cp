#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >

using namespace std;

int main(){
  
  faster
  int n;
  cin>>n;
  vi input(n);
  vi sum(n);
  
  
  for(int i = 0;i<n;i++){
    cin>>input[i];
    sum[i] = (i==0)?input[i]:sum[i-1]+input[i];
  }
  
  lld tot_sum = sum[n-1];
  int num_ways  = 0;
  
  for(int i = 0;i<n-1;i++)
    if(2*sum[i]==tot_sum)
      num_ways++;  
  
  cout<<num_ways<<endl;
}
