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

  int n;
  cin>>n;
  vector< string >input(n);
  for(int i=0;i<n;i++)cin>>input[i];

  int flag = 1;
  for(int i=0;i<n;i++){
    if(!flag)break;
    map< char,int >present;
    map< char,int >present2;
    for(int j=0;j<n;j++){
      if(present[input[i][j]]||present2[input[j][i]]){flag = 0;break;}
      present[input[i][j]] = 1;
      present2[input[j][i]] = 1;
    }
  }
  if(!flag){ cout<<"No"<<endl;return 0;}
  flag = 1;
  int largest_row = 0,largest_col = 0;
  for(int i=0;i<n;i++){
    if(largest_row>input[0][i]){ flag = 0;break;}
    if(largest_col>input[i][0]){ flag = 0;break;}
    largest_row = input[0][i];largest_col= input[i][0];
  }
  if(!flag) cout<<"Not Reduced\n";
  else cout<<"Reduced\n";
  #ifdef TM
    cerr<<"Time elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<" s.\n";
  #endif

}
