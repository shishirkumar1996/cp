#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >

using namespace std;

int main(){

  faster
  lld n,q;
  cin>>n>>q;
  
  vi input(n),query(q);
  cin>>input[0];
  for(int i =1;i<n;i++){ 
    lld inp;
    cin>>inp;
    input[i] = input[i-1]+inp;

  }
  
    
  for(int i =0;i<q;i++)
    cin>>query[i];
    
  lld top = input[0];
  lld index = 0;
 
  lld sum=0,num = 0;
  for(int i= 0;i<q;i++){
    
    sum+= query[i];
    lld index = upper_bound(input.begin(),input.end(),sum)-input.begin();
    if(index==n)
      sum = 0,num = n;
    else if(index==0)
      num = n;
    else
      num = n-index;
    
    cout<<num<<endl;    
  }
  
}
