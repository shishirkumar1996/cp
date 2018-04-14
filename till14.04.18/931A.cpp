#include<bits/stdc++.h>

using namespace std;


int calc(int a,int b){

  int diff = abs(a-b);
  int x = diff/2;
  int y = diff - x;
  
  return (x*(x+1))/2 + ((y+1)*y)/2;

}
int main(){
  ios::sync_with_stdio(false);
  int a,b;
  cin>>a>>b;
  cout<<calc(a,b)<<endl;

}
