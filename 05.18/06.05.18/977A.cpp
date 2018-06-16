#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int

using namespace std;

int main(){

  lld a,b;
  cin>>a>>b;
  
  for(int i = 1;i<=b;i++)
    if(a%10==0)
      a  = a/10;
    else
      a--;

  cout<<a<<endl;
}
