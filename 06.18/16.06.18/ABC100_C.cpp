#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld > 

using namespace std;


int main(){

  int n;
  cin>>n;
  vi input(n);
  for(int i = 0;i<n;i++) cin>>input[i];
  
  int ans = 0;
  for(int i = 0;i<n;i++)
    while(input[i]%2 == 0)ans++,input[i] = input[i]/2;
  
  cout<<ans<<endl;

}
