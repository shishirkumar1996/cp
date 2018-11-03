#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  
  string input;
  cin>>input;
  stack< char > process;
  
  int count[26],temp_count[26];
  for(int i=0;i<26;i++)count[i]=temp_count[i]= 0;
  
  for(int i=0;i<input.size();i++)count[input[i]-'a']++;
  
  int index = 0;
  string ans = "";
  for(int i=0;i<input.size();i++){
    while(count[index]==temp_count[index])index++;
    while(process.size() && process.top()<='a'+index){ 
      ans+= process.top();process.pop();
    }
    if(input[i]=='a'+index)ans += input[i];
    else process.push(input[i]);
    temp_count[input[i]-'a']++;
  }
  while(process.size()){ ans += process.top();process.pop(); }
  cout<<ans<<'\n';
}
