#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  faster
  int m,t,r;
  cin>>m>>t>>r;
  vi input(m);
  
  for(int i = 0;i<m;i++)cin>>input[i];
  
  if(t<r){cout<<-1<<endl;return 0;}
  
  int ans = 0;
  queue< int > process;
  int maxm = 0;
  
  for(int i = 0;i<m;i++){
    
    if(process.size()>=r && process.front()>= input[i])continue;
    
    while(process.size()<r || process.front()<input[i]){
      
      maxm = max(maxm+1,input[i]+t-r);
      cout<<input[i]<<" "<<maxm<<endl;
      process.push(maxm);
      if(process.front()<input[i]) process.pop();
      ans++;
    }
  }
  cout<<ans<<endl;

}
