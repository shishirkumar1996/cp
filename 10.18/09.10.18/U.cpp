#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define MOD (lld)(1e9+7)
#define trace(x) cerr<<#x<<":"<<x<<'\n';
#define trace2(a,n) { cerr<<#a<<" = "; fr(_,0,n) cerr<<a[_]<<' ';cerr<<'\n';}

using namespace std;

int main(){

  vector< double >input(7);
  double sum = 0;
  for(int i=1;i<=6;i++){ cin>>input[i];sum+= input[i]*i*1.0;}
  double x = 3.5;
//  trace(sum);
  
  double minm = 999999;
  for(int i=1;i<=6;i++){
    if(input[i]==0)continue;
    double z = (x-(sum-i*input[i]))/input[i];
//    trace(z);
    minm = min(minm,abs(z-i));
  }
  cout<<setprecision(3);
  cout<<fixed<<minm<<endl;
  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif
}

//x-(sum-i*pi)
