#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<" : "; for(int i=0;i<n;i++) cerr<<a[i]<<" ";cerr<<'\n';
#define vi vector< lld >

using namespace std;

int main(){

  lld n,x,y;
  cin>>n>>x>>y;
  
  vi output(n,1);
  y -= n;
  lld sum = n;
  while(sum<x && y>=0){
    output[0]++;
    sum += output[0]*output[0]-(output[0]-1)*(output[0]-1);
    y--;
  }
  if(y<0)cout<<-1<<endl;
  else{
    for(int i=0;i<n;i++)cout<<output[i]<<'\n';
  }
}
