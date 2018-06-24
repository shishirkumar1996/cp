#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define MAXM (lld)(1e10+7)

using namespace std;

int main(){
  
  faster
  int n;
  cin>>n;
  
  vi input(n);
  for(int i= 0;i<n;i++)cin>>input[i];
  
  lld ans = MAXM;
  int gate;
  for(int i= 0;i<n;i++){
    lld temp = ((input[i]+1)/n) *n+1+i;
    if(temp < input[i]+1) temp += n;
//    cout<<temp<<" "<<i+1<<endl;
    if(temp<ans) ans = temp,gate = i+1;
  }
  cout<<gate<<endl;
  

}
