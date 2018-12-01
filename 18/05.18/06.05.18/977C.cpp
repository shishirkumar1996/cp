#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >

using namespace std;


int main(){

  faster
  int n,k;
  cin>>n>>k;
  vi input(n);
  for(int i =0;i<n;i++)
    cin>>input[i];
  
  sort(input.begin(),input.end());
  if(k==0){
    if(input[0]==1)
      cout<<-1<<endl;
    else
      cout<<1<<endl;
  }
  else if(input[k]==input[k-1])
    cout<<-1<<endl;
  else
    cout<<input[k-1]<<endl;  
  
}
