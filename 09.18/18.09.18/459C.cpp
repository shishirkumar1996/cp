#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n,d;lld k;
  cin>>n>>k>>d;
  
  if(k==1){
    if(n>1){cout<<-1<<endl; return 0;}
    for(int i=1;i<=d;i++)cout<<1<<endl;
    return 0;
  }
  int minm = ceil(log(n*1.0)/log(k*1.0));
  if(minm>d){ cout<<-1<<endl; return 0; }
  
  for(int i=1;i<=minm;i++){
    for(int j=0;j<n;j++)
      cout<<((j%(lld)(pow(k,i)))/(lld)(pow(k,i-1)))+1<<" ";
    cout<<'\n';
  }
  for(int i=minm+1;i<=d;i++){
    for(int j=0;j<n;j++)cout<<1<<" ";
    cout<<'\n';
  }
}
