#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){

  int n;
  cin>>n;

  vi output;
  for(int i=2;i<=n;i+=2)output.push_back(i);
  for(int i=1;i<=n;i+=2) output.push_back(i);
  for(int i=2;i<=n;i+=2)output.push_back(i);
  
  cout<<output.size()<<endl;
  for(int i=0;i<output.size();i++)cout<<output[i]<<" "; cout<<endl;
}
