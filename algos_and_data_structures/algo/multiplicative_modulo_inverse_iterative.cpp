#include<bits/stdc++.h>

using namespace std;

//works only for co prime

int inv(int a,int m){
  
  int m0=m,t,q;
  int x0=0,x1 =1;
  
  if(m==1)return 0;
  
  while(a>1){
    q = a/m;
    t = m;
    m = a%m,a=t;
    t = x0;
    x0 = x1-q*x0;
    x1 = t;
  }
  if(x1<0) x1+=m0;
  return x1;
}

int main(){

  int a,m;
  cin>>a>>m;
  cout<<inv(a,m)<<endl;

}
