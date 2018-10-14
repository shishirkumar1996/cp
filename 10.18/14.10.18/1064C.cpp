#include<bits/stdc++.h>
#define lld long long int
#define vi vector< lld >
#define pr pair< lld,lld >
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  
  int n;
  string input;
  cin>>n>>input;
  char output[n];
  int num[26];
  for(int i=0;i<26;i++)num[i]=  0;
  for(int i=0;i<n;i++)num[input[i]-'a']++;
  
  int index = 0;
  for(int i=0;i<26;i++){
    for(int j=0;j<num[i];j++){
      output[index++] = 'a'+i;
    }
  }
  for(int i=0;i<n;i++)cout<<output[i];cout<<'\n';
  
}
