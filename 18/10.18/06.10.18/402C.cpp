#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define pr pair< int,int >
#define vp vector< pr >

using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,p;
    cin>>n>>p;
    int x = 1,y=2;
    int index =1;
    while(index<=2*n+p){
      cout<<x<<" "<<y<<'\n';
      if(y==n){x++; y = x+1;}
      else y++;
      index++;
    }
  }
  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif
}
