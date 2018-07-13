#include<bits/stdc++.h>
#define lld long long int

using namespace std;

int main(){
  
  string s;
  cin>>s;
  
  
  for(int i = 0;i<s.size()-1;i++){
    if(s[i] == 'a' || s[i] == 'i' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'n') continue;
    if(!(s[i+1] == 'a' || s[i+1] == 'i' || s[i+1] == 'e' || s[i+1] == 'o' || s[i+1] == 'u')){cout<<"NO"<<endl;return 0;}
  }
  int n=s.size()-1;
  if(!(s[n] == 'a' || s[n] == 'i' || s[n] == 'e' || s[n] == 'o' || s[n] == 'u' || s[n] == 'n')){cout<<"NO"<<endl;return 0;}
  cout<<"YES"<<endl;
}
