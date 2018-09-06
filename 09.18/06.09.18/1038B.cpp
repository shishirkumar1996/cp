#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){

  int n;
  cin>>n;
  if(n==1||n==2){cout<<"No"<<endl;return 0;}
  
  cout<<"Yes"<<endl;
  vi first,second;
  second.push_back(n);
  for(int i=1;i<n;i++)first.push_back(i);
  
  cout<<first.size()<<" ";
  for(int i=0;i<first.size();i++)cout<<first[i]<<" "; cout<<endl;
  cout<<second.size()<<" ";
  for(int i=0;i<second.size();i++)cout<<second[i]<<" ";cout<<endl;

}
