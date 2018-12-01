#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  int one,two;
  cin>>one>>two;
  
  lld timer_one = 0,timer_two =0;
  lld train_one=1,train_two=1;
  lld first = 0,second = 0;
  lld timer = 0;
  
  while(true){
    
    lld x = train_one*one,y= train_two*two;
    if(x<y){
      first += x-timer;
      timer = x;
      train_one++;
    } else if(x>y){
      second += y-timer;
      timer = y;
      train_two++;
    } else {
      if(one<two) second += y-timer;
      else first += x-timer;
      if(first<second){cout<<"Masha"<<endl;return 0;}
      else if(first>second){cout<<"Dasha"<<endl;return 0;}
      else {cout<<"Equal"<<endl; return 0;}
    }
  }
}
