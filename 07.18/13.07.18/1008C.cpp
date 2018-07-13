#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld,lld >
#define vi vector< lld >
#define vp vector< pr >


using namespace std;


int main(){
  
  faster
  int n;
  cin>>n;
  vi input(n);
  
  for(int i=0;i<n;i++)cin>>input[i];
  sort(input.begin(),input.end());
  
  int ans = 0;
  int left = 0,right = 1;
  while(right<n){
    if(input[left] == input[right]) right++;
    else {ans++;left++;right++;}
  }
  
  cout<<ans<<endl;

}
