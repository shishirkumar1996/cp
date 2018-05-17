#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false)
#define lld long long int

using namespace std;

int main(){
  
  lld q;
  cin>>q;
  
  int flag = 0;
  lld num= 0;
  for(lld i = 2;i*i<=q;i++){
  
    if(q%i==0 && !num)
      num = i, q = q/i;
    if(q%i==0 && q>i){
      cout<<"1\n"<<i*num<<endl;
      return 0;
    }
  }
  
  if(!num)
    cout<<"1\n0"<<endl;
  else
    cout<<2<<endl;
  

}
