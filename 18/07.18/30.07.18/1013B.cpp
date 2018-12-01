#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  faster
  int n,x;
  cin>>n>>x;
  multiset< int > process;
  vi input(n);
  
  for(int i=0;i<n;i++){
    cin>>input[i];
    process.insert(input[i]);
  }
  for(int i=0;i<n;i++)
    if(process.count(input[i])>1){cout<<0<<endl;return 0;}
  
  
  for(int i=0;i<n;i++){
    process.erase(input[i]);
    process.insert(input[i] & x);
    if(process.count(input[i] & x)>1){cout<<1<<endl;return 0;}
    process.erase(input[i] & x);
    process.insert(input[i]);
  }
  
  for(int i=0;i<n;i++){
    process.erase(input[i]);
    process.insert(input[i] & x);
  }
  for(int i=0;i<n;i++)
    if(process.count(input[i] & x)>1){cout<<2<<endl;return 0;}

  cout<<-1<<endl;

}
