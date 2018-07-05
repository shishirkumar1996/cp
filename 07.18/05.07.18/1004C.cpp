#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >

using namespace std;


int main(){

  int n;
  cin>>n;
  vi input(n);
  map< int, int > count;
  int total = 0;
  for(int i = 0;i<n;i++){
    cin>>input[i];
    if(!count[input[i]]) total++;
    count[input[i]]++;
  }
  
  map<int, int >temp;
  
  lld ans = 0;
  for(int i = 0;i<n;i++){
    temp[input[i]]++;
    
    if(temp[input[i]] == count[input[i]]) total--;
    if(temp[input[i]]>1) continue;
    ans+= total;
  }
  cout<<ans<<endl;
}
