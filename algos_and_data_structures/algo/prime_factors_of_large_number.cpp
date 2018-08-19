#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;


int main(){

  lld n;
  cin>>n;
  
  vi output;
  
  if(n%2==0)output.push_back(2);
  while(n%2==0)n=n/2;
  
  for(lld x = 3;x<=sqrt(n);x+=2){
    if(n%x==0){output.push_back(x);}
    while(n%x==0)n=n/x;
  }
  if(n!=1)output.push_back(n);
  for(int i=0;i<output.size();i++)cout<<output[i]<<" ";
  cout<<endl;

}
