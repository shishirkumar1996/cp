#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

lld gcd(lld a,lld b){ if(b==0)return a; return gcd(b,a%b); }


int main(){

  faster
  int n;
  cin>>n;
  lld ans;
  lld a,b;
  cin>>a>>b;
  vi process;
  map< lld, int> x;
  if(a%2==0){process.push_back(2);x[2]++;}
  
  while(a%2==0)a = a/2;
  for(lld i=3;i<=sqrt(a);i+=2){
    if(a%i==0 && !x[i]){process.push_back(i);x[i]++;}
    while(a%i==0)a= a/i;
  }
  if(a!=1 && !x[a]){process.push_back(a);x[a]++;}
  
  if(b%2==0 && !x[2]){process.push_back(2);x[2]++;}
  while(b%2==0)b=b/2;
  for(lld i=3;i<=sqrt(b);i+=2){
    if(b%i==0 && !x[i]){process.push_back(i);x[i]++;}
    while(b%i==0)b = b/i;
  }
  if(b!=1 && !x[b]){process.push_back(b);x[b]++;}
    
  for(int i=1;i<n;i++){
    lld first,second;
    cin>>first>>second;
    vi temp;
    for(int j=0;j<process.size();j++)if(first%process[j]==0 || second%process[j]==0)temp.push_back(process[j]);
    process=temp;
  }
  
  if(!process.size()){cout<<-1<<endl;}
  else cout<<process[0]<<endl; 
}
