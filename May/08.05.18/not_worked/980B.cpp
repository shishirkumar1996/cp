#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vc vector< char >
#define vcc vector< vc >

using namespace std;


int main(){
  int n,k;
  cin>>n>>k;
  vcc process(4);
  
  for(int i = 0;i<4;i++)
    for(int j = 0;j<n;j++)
      process[i].push_back('.');
  
  int flag = 0; 
  for(int i = 1;i<=k;i++){
    
    cout<<i<<endl;
    flag = 0;
    for(int j = 1;j<3;j++){
      for(int l = 1;l<n-1;l++){
        if(process[j][l] == '#')
         continue;
        
        
        lld short1 = 0,short2 = 0;
        lld dp1[4][n],dp2[4][n];
        dp1[0][0] = 1;
        for(int x = 0;x<4;x++)
          for(int y = 0;y<n;y++){
            if(x != 0 || y != 0)
              dp1[x][y] = 0;
            if( x> 0 && process[x-1][y] == '.')
              dp1[x][y] += dp1[x-1][y];
            if(y>0 && process[x][y-1] == '.')
              dp1[x][y] += dp1[x][y-1];  
          
          }
        dp2[3][0] = 1;
        for(int x = 3;x>=0;x--)
          for(int y = 0;y<n;y++){
//            cout<<x<<" "<<y<<endl;
            if(x != 3 || y != 0)
              dp2[x][y] = 0;
            if( x<3 && process[x+1][y] == '.')
              dp2[x][y] += dp2[x+1][y];
            if(y>0 && process[x][y-1] == '.')
              dp2[x][y] += dp2[x][y-1];  
          
//            cout<<x<<" "<<y<<dp2[x][y]<<endl;
          }
        cout<<dp1[3][n-1]<<" "<<dp2[0][n-1]<<" "<<j<<" "<<l<<endl;
        if(dp1[3][n-1] == dp2[0][n-1]){
          flag =1;
          break;
        }
        else process[j][l] = '.';
      }
      if(flag)
        break;
    }
  
    if(!flag)
      break;
  
  }
  if(!flag) cout<<"NO"<<endl;
  else{
    cout<<"YES"<<endl;
    for(int i = 0;i<4;i++){
      for(int j = 0;j<n;j++)
        cout<<process[i][j];    
      cout<<endl;
    } 
  }
  


}
