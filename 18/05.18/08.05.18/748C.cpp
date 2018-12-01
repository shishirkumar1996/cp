#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >

using namespace std;

int main(){

  int n;
  string input;
  cin>>n>>input;
  
  char horizontal,vertical;
  horizontal = vertical = 'X';
  lld ans = 0;
  for(int i= 0;i<input.size();i++){
    if(input[i]=='R'||input[i]=='L'){
      if(horizontal  == 'X')
        horizontal = input[i];
      else if(horizontal != input[i]){
        ans++;
        horizontal = input[i];
        vertical = 'X';
        continue;
      }
    }
    else if(input[i]=='U'||input[i]=='D'){
      if(vertical== 'X')
        vertical = input[i];
      else if(vertical != input[i]){
        ans++;
        horizontal = 'X';
        vertical = input[i];
        continue;
      }
    
    }
    
  }
  ans++;
  cout<<ans<<endl;


}
