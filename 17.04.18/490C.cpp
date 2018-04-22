#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;


void calc(lld a,lld b,string input){
  
  lld prefix[input.length()];
  lld suffix[input.length()];
  prefix[0] = (input[0]-'0')%a;
  int flag = 0;
  int index = -1;
  for(int i = 1;i<input.length();i++)
    prefix[i] = ((prefix[i-1]*10)%a + (input[i]-'0'))%a;  
  
  lld tens[input.length()];
  tens[input.length()-1] = 1%b;
  
  suffix[input.length()-1] = (input[input.length()-1]-'0')%b;
  
  for(int i = input.length()-2;i>=0;i--){
    tens[i] = (tens[i+1]*10)%b;
    suffix[i] = (tens[i]*(input[i]-'0')%b + suffix[i+1])%b;
  }
  
  for(int i= 0;i<input.length()-1;i++)
    if(prefix[i] == 0 && suffix[i+1]==0 && input[i+1] != '0'){
      flag = 1,index = i;break;
    }
  
  if(flag==1){
    cout<<"YES"<<endl;
    cout<<input.substr(0,index+1)<<endl;
    cout<<input.substr(index+1)<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}

int main(){
  faster
  lld a,b;
  string input;
  cin>>input>>a>>b;
  calc(a,b,input);

}
