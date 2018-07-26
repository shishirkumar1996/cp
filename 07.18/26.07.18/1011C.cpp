#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;

int main(){
  
  int n,m;
  cin>>n>>m;
  
  vi takeoff(n),land(n);
  int flag =1;
  for(int i=0;i<n;i++){ cin>>takeoff[i];
    if(takeoff[i] == 1) flag =0;
  }
  for(int i=0;i<n;i++){ cin>>land[i];
    if(takeoff[i] == 1) flag = 0;
  }
  if(!flag){cout<<-1<<endl;return 0;}
    
  double ans = m;
  ans = ans/(1.0-1.0/land[0]);

  for(int i=n-1;i>0;i--){
    ans = ans/(1.0-1.0/takeoff[i]);
    ans = ans/(1.0-1.0/land[i]);
  }
  ans = ans/(1.0-1.0/takeoff[0]);
  
  cout<<setprecision(10)<<ans-m<<endl;
}
