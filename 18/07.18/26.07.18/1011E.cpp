#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

lld gcd(lld a,lld b){
  if(b==0)return a;
  return gcd(b,a%b);
}

lld lcm(lld a,lld b){
  return (a*b)/gcd(a,b);
}


int main(){
  
  faster
  int n,k;
  cin>>n>>k;
  
  int ans = 1;
  lld x;
  cin>>x;
  x = x%k;
  if(x==0) x+= k;
  for(int i=1;i<n;i++){
    lld a;
    cin>>a;
    a = a%k;
    if(a==0) a+=k;
    x = gcd(x,a);
  }
  cout<<lcm(x,k)/x<<endl;
  vi output;
  for(int i=1;i<=lcm(x,k)/x;i++)output.push_back((x*i)%k);
  
  sort(output.begin(),output.end());
  for(int i=0;i<output.size();i++)cout<<output[i]<<" ";
  cout<<endl;
}
