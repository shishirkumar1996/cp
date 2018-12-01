#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = ";fr(_,0,n) cerr<<a[_]<<' ';cerr<<'\n';}
#define TM

using namespace std;

int main(){

  lld a,b;
  cin>>a>>b;
  a = a*2;
  b = b*3;
  lld six=0;
  int num_six;
  while(true){
    num_six = min(a,b)/6-six;
    six = min(a,b)/6;
//    trace(six);
    if(num_six==0)break;
    for(int i=1;i<=num_six;i++) if(a+2<b+3) a+=2; else b+=3;
    
  }
  cout<<max(a,b)<<endl;
  
  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif
}
