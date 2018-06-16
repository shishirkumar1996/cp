#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;


int main(){
  faster
  lld n,k;
  cin>>n>>k;
  
  vi input(n);
  for(int i=0;i<n;i++) cin>>input[i];
  
  sort(input.begin(),input.end());
  
  lld num = 0,maxm = 0,r=0,l=0,sum=0;
  for(int i = 0;i<n;i++){
    r = i;
    sum += input[i];
    while((r-l+1)*input[i] > sum + k){
      sum -= input[l];
      l++;
    }
    if((r-l+1)>maxm) maxm = r-l+1, num = input[i];
  }
  cout<<maxm<<" "<<num<<endl;

}
