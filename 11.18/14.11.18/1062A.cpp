#include<bits/stdc++.h>
#define lld long ong int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  
  int n;
  cin>>n;
  vi input(n);
  int ans = 0;
  int num = 1;
  for(int i=0;i<n;i++){
    cin>>input[i];
    if(i==0)continue;
    if(input[i]==input[i-1]+1)num++;
    else{  ans = max(ans,num-2); num = 1;  }
  }
  ans = max(ans,num-2);
  if(input[0]==1 && input[n-1] == n) ans = n-1;
  if(input[n-1]==1000 && input[0] == 1000-n+1) ans = n-1;
  cout<<ans<<'\n';
}
