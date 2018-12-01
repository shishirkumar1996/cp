#include<bits/stdc++.h>
#define vi vector< int >
#define faster ios_base::sync_with_stdio(false);cin.tie(0):

using namespace std;

int main(){

  int n,m;
  cin>>n>>m;
  
  map< int,int > process;
  for(int i=0;i<m;i++){
    int a;
    cin>>a;
    process[a]++;
  }

  int ans = 0;
  int index = 1;
  while(true){
    
    int x = 0;
    for(int i=1;i<=100;i++) x += process[i]/index;
    if(x>=n) ans = index; else break;
    index++;
  }
  cout<<ans<<endl;
}
