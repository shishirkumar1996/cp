#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;


int main(){

  faster
  int n;
  cin>>n;
  
  set< lld > input;
  
  for(int i= 0;i<n;i++){
    lld a;
    cin>>a;
    input.insert(-a);  
  }

  while(true){
    lld top = -(*input.begin());
//    cout<<top<<endl;
    while(top>0){
      lld x = top/2;  
      if(x == 0 || input.count(-x) == 1){top = top/2;continue;}
      else {
        input.erase(input.find(-top));
        input.insert(-x);
//        cout<<top<<" "<<x<<endl;
        break;
      }
    }
    if(!top) break;
  }
  
  
  for(set< lld >::iterator it = input.begin(); it != input.end();it++)cout<<-(*it)<<" ";
  cout<<endl;

}
