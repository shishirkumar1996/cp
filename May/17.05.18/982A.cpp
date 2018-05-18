#include<bits/stdc++.h>
#define  faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  string input;
  cin>>input;
  
  input = "0"+input+"0";
  if(input.find("000") != -1 || input.find("11") != -1)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;

}

