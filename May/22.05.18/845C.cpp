#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define pr pair< lld, lld >
#define vp vector< pr >

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  vp input(n);
  for(int i  = 0;i<n;i++)cin>>input[i].first>>input[i].second;
  
  sort(input.begin(),input.end());
  
  pr first = make_pair(-1,-1),second = make_pair(-1,-1);
  
  for(int i = 0;i<n;i++){
  
    if(first.second <= second.second){
      if(first.second >= input[i].first){cout<<"NO"<<endl;return 0;}
      first = input[i];
    } else{
      if(second.second>=input[i].first){cout<<"NO"<<endl;return 0;}
      second = input[i];
    }
  
  }
  cout<<"YES"<<endl;
}
