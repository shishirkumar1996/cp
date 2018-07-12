#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >


using namespace std;

int main(){

  lld a00,a01,a10,a11;
  cin>>a00>>a01>>a10>>a11;
  
  if(a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0){cout<<0<<endl;return 0;}
  lld zero = 0,first = 0;
  
  while(true){
    lld num = (zero*(zero-1))/2;
    if(num == a00){break;}
    if(num>a00){cout<<"Impossible"<<endl;return 0;}
    zero++;
  }
  
  while(true){
    lld num = (first*(first-1))/2;
    if(num == a11){break;}
    if(num>a11){cout<<"Impossible"<<endl;return 0;}
    first++;
  }  
  if(zero == 0 && a10+ a01 != 0) zero++;
  if(first == 0 && a10 + a01 != 0)first++;
   
  if(zero*first != a10+a01){
    cout<<"Impossible"<<endl;return 0;
  }  

  lld before=zero,middle =0,after=0;
  
  if(first){
   before = a01/first;
   middle = (first - a01%first)%first;
   after = zero - before;
   if(middle) after--;
  }
  string output = "";
  for(int i= 0;i<before;i++)output += "0";
  for(int i= 0;i<middle;i++) output+= "1";
  if(middle) output+= "0";
  for(int i= 0;i<first-middle;i++) output += "1";
  for(int i =0;i<after;i++) output+= "0";
  cout<<output<<endl;

}
