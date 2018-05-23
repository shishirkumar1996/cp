#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vs vector< string >

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  vs input(n);
  for(int i =0;i<n;i++) cin>>input[i];
  
  string ans = input[0];
  for(int i = 1;i<n;i++){
    while(ans.length() && input[i].substr(0,ans.length())!= ans) ans = ans.substr(0,ans.length()-1);
  }
  cout<<ans.length()<<endl;
}
