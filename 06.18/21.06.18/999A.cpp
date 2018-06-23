#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >


using namespace std;


int main(){

  int ans = 0;
  int n,k;
  cin>>n>>k;
  
  vi input(n);
  for(int i = 0;i<n;i++) cin>>input[i];
  
  int left = 0,right = n-1;
  for(left = 0;left<n;left++) if(input[left] > k) break; else ans++;
  
  for( right = n-1;right>left;right--) if(input[right]>k) break; else ans++;
  cout<<ans<<endl;

}
