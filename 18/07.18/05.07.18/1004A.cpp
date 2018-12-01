#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
  
  int n;lld d;
  cin>>n>>d;
  
  vi input(n);
  for(int i = 0;i<n;i++) cin>>input[i];
  
  int ans = 2;
  
  for(int i =1;i<n;i++){
    if(input[i]-input[i-1]==2*d) ans++;
    else if(input[i]-input[i-1] > 2*d) ans += 2;
  }
  cout<<ans<<endl;
}
