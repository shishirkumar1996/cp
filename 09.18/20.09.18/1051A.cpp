#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    string input;
    cin>>input;
    int small = 0,big = 0,digit = 0;
    for(int i=0;i<input.length();i++){
      if(input[i]>='a' && input[i]<='z') small++;
      else if(input[i]>='A' && input[i]<='Z') big++;
      else digit++;
    }
    if(!small && !big){ input[0] = 'A'; input[1] = 'a'; }
    else if(!small && !digit){ input[0] = 'a';input[1] = '0';}
    else if(!big && !digit){ input[0] = 'A'; input[1] = '0';}
    else if(!small){
      if(input[0]>='A' && input[0]<='Z'){
        if(big==1)input[1]='a';
        else input[0] = 'a';
      }
      if(input[0]>='0' && input[0]<='9'){
        if(digit==1)input[1] = 'a';
        else input[0] = 'a';
      }
  }
  else if(!big){
    if(input[0]>='a' && input[0]<='z'){
      if(small==1)input[1]='A';
      else input[0] = 'A';
    }
    if(input[0]>='0' && input[0]<='9'){
      if(digit==1)input[1] = 'A';
      else input[0] = 'A';
    }
  }
  else if(!digit){
    if(input[0]>='A' && input[0]<='Z'){
      if(big==1)input[1]='0';
      else input[0] = '0';
    }
    if(input[0]>='a' && input[0]<='z'){
      if(small==1)input[1] = '0';
      else input[0] = '0';
    } 
  }
  cout<<input<<endl;
}  
}
