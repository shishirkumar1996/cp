#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define pr pair< int, int >
#define vp vector< pr >
#define lld long long int

using namespace std;

int main(){
  
  faster
  int n,q,c;
  cin>>n>>q>>c;
  vp input(n);
  int brightness[n];
  for(int i =0;i<n;i++)
    cin>>input[i].first>>input[i].second>>brightness[i];
  
  int dp[101][101][c+1];
  
  
  int point[101][101][c+1];
    for(int i = 0;i<=100;i++)
      for(int j = 0;j<=100;j++)
        for(int k = 0;k<=c;k++)
          point[i][j][k]=0;
  
  for(int i = 0;i<input.size();i++){
    int x = input[i].first;
    int y = input[i].second;
    point[x][y][0] = brightness[i];
    for(int j =1;j<=c;j++)
      point[x][y][j] = (brightness[i]+j)%(c+1);
  
  }
  
  for(int k = 0;k<=c;k++){
    for(int i = 0;i<=100;i++)
      for(int j = 0;j<=100;j++){
        if(i==0||j==0){ // these are the outlying points
          dp[i][j][k] = 0;
          continue;
        }
        dp[i][j][k] = point[i][j][k]+dp[i-1][j][k]+dp[i][j-1][k]-dp[i-1][j-1][k];
      }
  }  


  for(int i =1 ;i<=q;i++){
    lld t,lower_x,lower_y,upper_x,upper_y;
    cin>>t>>lower_x>>lower_y>>upper_x>>upper_y;
    t = t%(c+1);
    
    
    lld ans = dp[upper_x][upper_y][t] - dp[lower_x-1][lower_y][t] - dp[lower_x][lower_y-1][t] + dp[lower_x-1][lower_y-1][t];
    cout<<ans<<endl;
  }

}

