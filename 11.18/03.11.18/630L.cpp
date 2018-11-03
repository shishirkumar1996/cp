#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){

  string n;
  cin>>n;
  
  string temp = "";
  
  temp += n[0];
  temp += n[2];temp += n[4];temp += n[3]; temp += n[1];
  lld num = stoll(temp);
  lld output = num;
  for(int i=0;i<4;i++){
    output *= num;
    output  = output%100000;
  }
  string ans = to_string(output);
  while(ans.size()<5)ans = "0"+ans;
  cout<<ans<<'\n';
}
