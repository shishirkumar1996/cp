#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  string input;
  cin>>input;
  
  int link = 0,pearl = 0;
  for(int i = 0;i<input.size();i++)
    (input[i]=='-')?link++:pearl++;

  if(pearl==0 || ((link/pearl)*pearl == link))
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}
