#include<bits/stdc++.h>

using namespace std;


string calc(int n,int m){
  
  if(n>m+1 || m > 2*n+2)
    return "-1";
    
  string result = "";
  int counter;      //0 means 0 turn 1 means 1 turn
  if(n>m)
    counter = 0;
  else
    counter = 1;
  while(n>0 || m>0){
    if(counter==0 && n>0){
      result += "0";
      n--;
      counter = 1;
    }
    else {
      if(m>n && m>1){
        result += "11";
        m-=2;
        counter = 0;
      }
      else if(m>0)
      {
        result += "1";
        m-=1;
        counter = 0;
      }
    }
  
  }
  
  return result;

}

int main(){
  int n,m;
  cin>>n>>m;
  cout<<calc(n,m)<<endl;


}
