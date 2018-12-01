#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

int main(){

  int n,m;
  cin>>n>>m;
  
  vp input(m);
  for(int i= 0;i<m;i++) cin>>input[i].first>>input[i].second;
  
  char output[n];
  
  for(int i= 0;i<n;i++) if(i%2==0) output[i] = '0'; else output[i] = '1';
  
  for(int i= 0;i<n;i++)cout<<output[i];
  cout<<endl;
}
