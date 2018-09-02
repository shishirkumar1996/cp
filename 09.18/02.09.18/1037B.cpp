#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){

  int n;
  lld s;
  cin>>n>>s;
  
  vi input(n);
  for(int i=0;i<n;i++) cin>>input[i];

  sort(input.begin(),input.end());
  
  lld ans = 0;
  lld temp1=0,temp2=0,mid = 0;
  for(int i=0;i<n/2;i++)if(s<input[i])temp1 += abs(s-input[i]);
  for(int i=n/2+1;i<n;i++) if(s>input[i]) temp2+= abs(s-input[i]);
  
  if(input[n/2]==s){cout<<0<<endl;return 0;}
  else if(input[n/2]>s) ans = temp1+abs(s-input[n/2]);
  else if(input[n/2]<s) ans = temp2+abs(s-input[n/2]);
  cout<<ans<<endl;
}

