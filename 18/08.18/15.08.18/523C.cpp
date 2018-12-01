#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  string s,t;
  cin>>s>>t;
  
  int left_index,right_index;
  int index=0,i;
  for(i=0;i<t.length() && index<s.length();i++)
    if(s[index]==t[i])index++;

  left_index = i-1;
  index = s.length()-1;
  for(i=t.length()-1;i>=0 && index>=0;i--)
    if(s[index]==t[i])index--; 
  
  right_index = i+1;
  cout<<max(0,right_index-left_index)<<endl;
}
