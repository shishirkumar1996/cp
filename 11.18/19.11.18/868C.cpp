#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n,k;
  cin>>n>>k;
  
  int num[1<<k];
  for(int i=0;i<(1<<k);i++)num[i] = 0;
  
  for(int i=0;i<n;i++){
    int temp = 0;
    for(int j=0;j<k;j++){
      int a;
      cin>>a;
      temp = temp*2+a;
    }
    num[temp]++;
  }
  if(num[0]){ cout<<"YES\n";return 0;}
  for(int i=1;i<(1<<k);i++)
    for(int j=i+1;j<(1<<k);j++){
      if((i&j) !=  0)continue;
      if(num[i] && num[j]){ cout<<"YES\n"; return 0;  }
    }
  cout<<"NO\n";
}
