#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
#define vii vector< vi >

using namespace std;


int main(){

  faster
  lld n;
  cin>>n;
  vi input(n+1);
  
  for(int i = 1;i<=n;i++)
    cin>>input[i];
    
  lld m;
  cin>>m;
  lld minm = 0;
  for(int i =1;i<=m;i++){
    lld w,h;
    cin>>w>>h;
    lld ans = max(minm,input[w]);
    
    minm = ans+h;
    cout<<ans<<endl;
  }
}
