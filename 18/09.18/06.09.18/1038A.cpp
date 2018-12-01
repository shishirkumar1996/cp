#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){

  int n,k;
  cin>>n>>k;
  
  string input;
  cin>>input;
  map< int,int > process;
  
  for(int i=0;i<input.size();i++) process[input[i]-'A']++;

  int maxm = process[0];
  for(int i=1;i<k;i++)maxm = min(maxm,process[i]);
  cout<<maxm*k<<endl;  
}
