#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<": "; for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n'; }

using namespace std;

int main(){
  string input;
  cin>>input;
  int n = input.length();
  int x[26];
  for(int i=0;i<26;i++)x[i] = 0;
  
  for(int i=0;i<n;i++)x[input[i]-'a']++;
  
  int l = 0,index = 25;
  while(l<index){
    while(l<index  &&x[l]%2==0) l++;
    while(index>l && x[index]%2==0)index--;
    if(index != l){ x[l]++; x[index]--; }
  }
  
  string ans = "";
  index = -1;
  for(int i=0;i<26;i++){
    if(x[i]%2==1)index = i;
    for(int j=0;j<x[i]/2;j++) ans += (i+'a');
  }
  string temp = ans;
  reverse(temp.begin(),temp.end());
  if(index != -1) ans +=  (index+'a');
  ans += temp;
  cout<<ans<<'\n';
}
