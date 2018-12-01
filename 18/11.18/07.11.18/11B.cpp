#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
  
  lld n;
  cin>>n;
  n = abs(n);
  
  lld index = 0;
  while(true){
    
    lld x = (index*(index+1))/2;
    if(x==n){ cout<<index<<'\n';return 0;}
    if(x>n && (x-n)%2==0){ cout<<index<<'\n';return 0;}
    index++;
  }

}
