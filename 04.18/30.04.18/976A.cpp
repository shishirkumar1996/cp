#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;


int main(){

  int n;
  cin>>n;
  string s;
  cin>>s;
  int num_zeroes=0;
  if(s=="0"){
    cout<<"0"<<endl;
    return 0;
  }
  for(int i = 0;i<s.length();i++) if(s[i]=='0') num_zeroes++;
  
  cout<<'1';
  for(int i = 0;i<num_zeroes;i++)
    cout<<'0';
  cout<<endl;

}
