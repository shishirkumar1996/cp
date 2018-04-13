#include<bits/stdc++.h>


#define lld long long int
using namespace std;


lld calc(lld num){
  
  if(num%2 != 0){
    if(num < 9 || num == 11)
      return -1;
   
    return 1+(num-9)/4;
  }
  else if(num%2==0){
    if(num < 4)  
      return -1;
  
    if(num%4 == 0)
      return num/4;
    else
      return 1+(num-6)/4;
  }

}


int main(){

  ios::sync_with_stdio(false);
  
  int q;
  cin>>q;
  while(q--){
    lld num;
    cin>>num;
    cout<<calc(num)<<endl; 
  }
  

}
