#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){
  
  string input;
  cin>>input;
  
  int n= input.length();
  int lower[n],upper[n];
  
  lower[0] = 0,upper[0] = 0;
  for(int i=1;i<=n;i++){
    lower[i] = lower[i-1];
    upper[i]  = upper[i-1];
    if(input[i-1]>='A' && input[i-1]<='Z') upper[i]++; else lower[i]++;
  }
  int ans = INT_MAX;
  ans = upper[n];
  for(int i=1;i<=n;i++){
    int upper_change = upper[n]-upper[i];
    int lower_change = lower[i] - lower[0];
    ans = min(ans,upper_change+lower_change);
  }
  cout<<ans<<endl;
}
