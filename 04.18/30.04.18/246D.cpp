#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define st set< int >
#define vs vector< st >
#define vi vector< int >

using namespace std;

int main(){

  faster
  int n,m;
  cin>>n>>m;
  bool present[(int)1e5+1];
  for(int i = 0;i<=1e5;i++)
    present[i] = false;
  vi color(n+1);
  for(int i = 1;i<=n;i++){ 
    cin>>color[i];  
    present[color[i]] = true;
  }
  
  vs process(1e5+1);
  for(int i =1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    if(color[a] != color[b]){
      process[color[a]].insert(color[b]);
      process[color[b]].insert(color[a]);
    }
  }
  
  int maxCol= 0;
  int max = -1;
  for(int i =1 ;i<=1e5;i++){
    int size = process[i].size();
    if(size>max && present[i]==true){
      max = size,maxCol = i;
    }
    }
  
  cout<<maxCol<<endl;

}


