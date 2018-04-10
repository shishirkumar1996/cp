#include<bits/stdc++.h>

using namespace std;



int calc(int n,int m){
  
  int count = 0;
  
  while(true){
    
    if(n==0||m==0||(n==1 && m==1))
      break;
    if(n>m)
      n-=2,m-=1,count++;
    else
      m-=2,n-=1,count++;
  }
  
  return count;  

}


int main(){

  int n,m;
  cin>>n>>m;
  cout<<calc(n,m)<<endl;


}
