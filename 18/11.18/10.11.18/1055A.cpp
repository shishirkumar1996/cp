#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  
  int n,s;
  cin>>n>>s;
  s--;
  vi first(n),second(n);
  for(int i=0;i<n;i++)cin>>first[i];
  for(int i=0;i<n;i++)cin>>second[i];
  
  if(first[0]==0 ||(first[s]==0 && second[s] == 0)){ cout<<"NO\n";return 0;}
  
  if(first[s]==1){ cout<<"YES\n";return 0;}
  int flag = 0;
  for(int i=s+1;i<n;i++)if(first[i]==1 && second[i] == 1){ flag = 1;break; }
  if(flag) cout<<"YES\n"; else cout<<"NO\n";
  
}
