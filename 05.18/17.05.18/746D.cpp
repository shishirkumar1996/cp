#include<bits/stdc++.h>
#define lld long long int

using namespace std;

int main(){

  int n,k,a,b;
  cin>>n>>k>>a>>b;
  
  string output="";
  if( (a>b && a > (b+1)*k) || (b>a && b> (a+1)*k) ){
    cout<<"NO"<<endl;
    return 0;
  }

  int turn = 0;
  if(a>=b) turn = 1; else turn = 0;
  while(n>0){
  
    if(turn == 1){
      int dist = min(n,min(k,max(a-b+1,1)));
      int temp = dist;
      while(dist--)
        output += "G";
      n -= temp;
      a -= temp;
      turn = 0;
    }else{
      int dist = min(n,min(k,max(1,b-a+1)));
      int temp = dist;
      while(dist--) output += "B";
      n-= temp;
      b-= temp;
      turn = 1;
    }  
  
  }
  cout<<output<<endl;

}
