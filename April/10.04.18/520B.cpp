#include<bits/stdc++.h>
#include<cmath>

using namespace std;

int calc(int n,int m){
  //n is the initial number
  // m is the final number
  if(m<n)
    return n-m;
  
  int count = 0;   
  while(m>n){
    if(m%2==0)
      m/=2;
    else
      m++;
    count++;
  }
  count += (n-m);
  return count;
}



int main(){
  int n,m;
  cin>>n>>m;
  cout<<calc(n,m)<<endl;
}
