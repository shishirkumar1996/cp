#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define NUM (lld)(2e5+7)

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  
  vii output(NUM);
  map< lld,int > x;
  set< lld > process;
  int size = 1;
  lld a;
  cin>>a;
  output[0].push_back(a);
  x[a] = 0;
  process.insert(a);
  
  for(int i=1;i<n;i++){
    lld a;
    cin>>a;
    set< lld >::iterator it = lower_bound(process.begin(),process.end(),a);
    if(it==process.begin()){
      output[size].push_back(a);
      x[a] = size;
      size++; 
    } else {
      lld y = *(prev(it,1));
      process.erase(prev(it,1));
      output[x[y]].push_back(a);
      x[a] = x[y];
    }
    process.insert(a);
  }
  for(int i=0;i<size;i++){
    for(int j=0;j<output[i].size();j++)cout<<output[i][j]<<" ";
    cout<<endl;
  }

}
