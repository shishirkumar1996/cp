#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  
  int n,a,b;
  cin>>n>>a>>b;
  
  vi input(n);
  for(int i=0;i<n;i++)cin>>input[i];
  
  int ans = 0;
  for(int i=0;i<n/2;i++){
    if(input[i]==0){
      if(input[n-1-i]==1){cout<<-1<<endl;return 0;}
      else if(input[n-1-i]==2) ans+= a;
    } else if(input[i]==1){
      if(input[n-1-i]==0){cout<<-1<<endl;return 0;}
      else if(input[n-1-i]==2) ans += b;
    } else if(input[i]==2){
      if(input[n-1-i]==0) ans += a;
      else if(input[n-1-i]==1) ans += b;
      else if(input[n-1-i]==2) ans += 2*min(a,b);
    }
  } 
  if(n%2==1 && input[n/2]==2) ans += min(a,b);
  cout<<ans<<endl;
}
