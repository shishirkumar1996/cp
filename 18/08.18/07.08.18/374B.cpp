#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  string input;
  cin>>input;
  
  lld ans = 1;
  lld temp = 0;
  int i=0;
  while(i<input.length()){
    temp = 0;
    if(i<input.length()-1 && (input[i]-'0'+input[i+1]-'0')==9){
      temp = 2;
      i++;
      while(i<input.length()-1 && (input[i]-'0'+input[i+1]-'0')==9){
        temp++;i++;
      }
      if(temp%2==1)ans *= (temp+1)/2;
    } else i++;
  }
  cout<<ans<<endl;

}
