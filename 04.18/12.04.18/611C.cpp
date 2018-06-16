#include<bits/stdc++.h>

#define lld long long int
#define vi vector < lld >
#define vii vector < vi >

using namespace std;

int main(){

  ios::sync_with_stdio(false);
  
  int w,h;
  cin>>w>>h;
  
  char input[w+1][h+1];
  
  for(int i = 0;i<=w;i++)
    for(int j = 0;j<=h;j++){
      if(i==0 || j==0)
        continue;
      char ct;
      cin>>ct;
      input[i][j] = ct;
    }
    
  
  lld hor[w+1][h+1];
  lld ver[w+1][h+1];
  
  for(int i = 0;i<=w;i++)
    for(int j = 0;j<=h;j++)
      hor[i][j] = ver[i][j] =  0;
  
  for(int i =1;i<=w;i++)
    for(int j = 1;j<=h;j++)
    {
      ver[i][j] = (input[i][j]=='.' && input[i-1][j] == '.')?(ver[i][j-1]+ver[i-1][j]-ver[i-1][j-1]+1):(ver[i][j-1]+ver[i-1][j]-ver[i-1][j-1]);
      hor[i][j] = (input[i][j]=='.' && input[i][j-1] == '.')?(hor[i][j-1]+hor[i-1][j]-hor[i-1][j-1]+1):(hor[i][j-1]+hor[i-1][j]-hor[i-1][j-1]);
//      cout<<i<<" "<<j<<" "<<hor[i][j]<<" "<<ver[i][j]<<endl;
    }
//  cout<<dp[4][1]<<endl;
  int q;
  cin>>q;
  for(int i = 0;i<q;i++){
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    lld answer = ver[r2][c2] - ver[r2][c1-1] - ver[r1][c2] + ver[r1][c1-1];
    answer += hor[r2][c2] - hor[r1-1][c2] - hor[r2][c1] + hor[r1-1][c1];
   
    
    cout<<answer<<endl;
  }

}
