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

  string input;
  cin>>input;
  
  int n= input.length();
  
  bool pal[n][n];
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)pal[i][j] = false;
  for(int l=1;l<=n;l++){
    for(int i=0;i<n-l+1;i++)
      if(l==1)pal[i][i] = true;
      else if(l==2){
        if(input[i]==input[i+1]){cout<<"Or not.\n"; return 0;}
      } else{
        if(input[i]==input[i+l-1] && pal[i+1][i+l-2]){
          pal[i][i+l-1] = true;
          if(l%2==0){cout<<"Or not.\n";return 0;}
        }
      }
  }
  cout<<"Odd.\n";

  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif

}
