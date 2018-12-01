#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  faster
  string s1,s2;
  cin>>s1>>s2;
  
  if(s1.length()>s2.length()) swap(s1,s2);

  int ans = 0;
  int lc = 0;
  
  string process = "";
  for(int i = 0;i<s1.length()/2;i++){
   
    if(s1.length()%(i+1) != 0) continue;
    
    process = s1.substr(0,i+1);
    int flag = 1;
    for(int j = 0;j<s1.length();j+= i+1)
    if(s1.substr(j,i+1)!=process){ flag = 0;break;}
    
    if(flag) { lc = i+1;break; }
  }
  if(lc==0 || (s2.length()%lc != 0)){ cout<<0<<endl;return 0; }
  int flag = 1;
  for(int i = 0;i<s2.length();i+= lc)
    if(s2.substr(i,lc) != process) { flag = 0;break;}
  
  if(!flag){ cout<<0<<endl;return 0; }
  for(int i = lc;i<=s1.length();i += lc)
    if(s1.length()%i == 0 && s2.length()%i == 0) ans++;
     
  cout<<ans<<endl;
}
