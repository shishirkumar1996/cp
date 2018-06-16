#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >

using namespace std;

lld calc(lld w,lld l,vi input){
  
  lld sum[w];
  sum[0] = 0;
  for(int i = 1;i<w;i++)
    sum[i] = sum[i-1]+input[i];
    
  lld maxm = INT_MAX;
  for(int i = w;i>l;i-=l){
    lld diff = sum[i-1]-sum[i-l-1];
    maxm = min(maxm,diff);
    
  }
  return maxm;

}

int main(){
  
  faster
  lld w,l;
  cin>>w>>l;
  vi input(w);
  for(int i =1;i<w;i++)
    cin>>input[i];
  
  cout<<calc(w,l,input)<<endl;

}
