#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  string input;
  cin>>input;
  bool taken[10];
  for(int i=0;i<10;i++)taken[i] = false;
  
  int num_zeroes = 0;
  lld ans = 1;
  int times = 10;
  if(input[0]>='A' && input[0]<='J'){ 
    ans = ans*9;times--; 
    taken[input[0]-'A']=true;
  }
  else if(input[0]=='?')ans = ans*9;
  
  for(int i=1;i<input.size();i++){
    if(input[i]>='A'&&input[i]<='J' && !taken[input[i]-'A']){ 
      ans=ans*times,times--; 
      taken[input[i]-'A']=true;
    }
    else if(input[i]=='?') num_zeroes++;
  }
  
  cout<<ans;
  for(int i=0;i<num_zeroes;i++)cout<<'0';
  cout<<endl;
}
