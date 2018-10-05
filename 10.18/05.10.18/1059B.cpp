#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vc vector< char >
#define vcc vector< vc >

using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  vcc input(n);
  int num = 0;
  bool drawn[n][m];
  for(int i=0;i<n;i++)for(int j=0;j<m;j++){
    drawn[i][j] = false;
    char ct;
    cin>>ct;
    input[i].push_back(ct);
    if(ct=='#')num++;
  }
  int x = 0;
  for(int i=1;i<n-1;i++){
    for(int j=1;j<m-1;j++){
      int sum = 0;
      for(int k=-1;k<=1;k++)for(int l=-1;l<=1;l++){
        if(k==0 && l==0)continue;
        if(input[i+k][j+l]=='#')sum++;
      }
      if(sum<8)continue;
      for(int k=-1;k<=1;k++)for(int l=-1;l<=1;l++){
        if(k==0 && l==0)continue;
        if(input[i+k][j+l]=='#' && !drawn[i+k][j+l]){
          drawn[i+k][j+l] = true;
          x++;
        }
      }
    }
  }
  if(x==num)cout<<"YES"<<endl; else cout<<"NO"<<endl;
}
