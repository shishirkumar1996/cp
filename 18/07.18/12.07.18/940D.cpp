#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);
#define MAXM (lld)(1e9)
#define vi vector< lld >

using namespace std;


int main(){

  int n;
  cin>>n;
  vi input(n);
  string b;
  for(int i= 0;i<n;i++)cin>>input[i]; cin>>b;
  
  lld l = -MAXM, r = MAXM;
  
  for(int i= 4;i<n;i++){
    if(b[i] == '0'){
      if(b[i-1] == '1' && b[i-2] == '1'&& b[i-3] =='1' && b[i-4] == '1'){
        lld minm = min(input[i],min(input[i-1],min(input[i-2],min(input[i-3],input[i-4]))));
        r = min(minm-1,r);
      }
    }
    else if(b[i] == '1'){
      if(b[i-1] == '0' && b[i-2] == '0'&& b[i-3] =='0' && b[i-4] == '0'){
        lld maxm = max(input[i],max(input[i-1],max(input[i-2],max(input[i-3],input[i-4]))));
        l = max(maxm+1,l);
      }
    }
  }
  cout<<l<<" "<<r<<endl;

}
