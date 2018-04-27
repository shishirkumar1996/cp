#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define mod (lld)(1e9+7)

using namespace std;


lld calc(string input){

  map<char,int> label;
  for(int i = 0;i<10;i++)
    label[i+'0'] = i;
  
  for(int i = 0;i<26;i++)
    
    label[i+'A'] = i+10;
  for(int i = 0;i<26;i++)
    label[i+'a'] = i+36;
  
  label['-'] = 62;
  label['_'] = 63;
  
  lld cost = 1;
  
  for(int i = 0;i<input.length();i++){
    
    lld part = 1;   
    int z = label[input[i]];
    int num_ones = 0;
    int num_zeroes = 6;
    while(z>0){
      int rem = z%2;
      if(rem)
        num_ones++;
      z = z/2;
    }
    num_zeroes -= num_ones;
    part = ((lld)pow(3,num_zeroes))%mod;
    cost = (cost*part)%mod;
  }
  
  return cost;  

}

int main(){


  string input;
  cin>>input;
  cout<<calc(input)<<endl;

}
