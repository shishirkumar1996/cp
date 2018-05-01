#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  vector< string > input(n);
  for(int i = 0;i<n;i++) cin>>input[i];    
  
  set< set< char > > output;
  for(int i =0;i<n;i++){
    set< char > mid;
    for(int j = 0;j<input[i].size();j++) mid.insert(input[i][j]);
    
    output.insert(mid);
  }
  
  int size = output.size();
  cout<<size<<endl;


}
