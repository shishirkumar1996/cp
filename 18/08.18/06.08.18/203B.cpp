#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >

using namespace std;

int main(){

  faster
  int n,m;
  cin>>n>>m;
  
  int sq[n+1][n+1];
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) sq[i][j] = 0;
  
  int output[m+1][2];
  for(int i=1;i<=m;i++)cin>>output[i][0]>>output[i][1];
  
  for(int i=1;i<=m;i++){
    int a=output[i][0],b=output[i][1];
    sq[a][b] = 1;
    
    for(int j=-1;j<=1;j++){
      for(int k=-1;k<=1;k++){
        int center_x = a+j,center_y = b+k;
        if(center_x>n-1 || center_x < 2 || center_y > n-1 || center_y<2)continue;
        int flag = 1;
        for(int l=-1;l<=1;l++){
          if(!flag)break;
          for(int m=-1;m<=1;m++){
            if(center_x+l>=1 && center_x+l<=n && center_y+m>=1 && center_y+m<=n && !sq[center_x+l][center_y+m]){flag= 0;break;}
          }
        }
        if(flag){cout<<i<<endl;return 0;}
      }
    }
  }
  cout<<-1<<endl;

}
