#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){
  
  faster
  int n;
  cin>>n;
  vi input(n/2);
  
  for(int i = 0;i<n/2;i++) cin>>input[i];
  
  sort(input.begin(),input.end());
  int black = 0,white = 0;

  for(int i = 0;i<n/2;i++) black =black+abs(2*i+1-input[i]),white = white+abs(2*i+2-input[i]);
  
  cout<<min(black,white)<<endl;  
  
}
