#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  int n;
  cin>>n;
  int odd_diff[4],even_diff[4];
  for(int i=0;i<4;i++)odd_diff[i] = even_diff[i] = 0;
  
  char input[4][n][n];
  for(int i=0;i<4;i++){
    for(int j=0;j<n;j++)for(int k=0;k<n;k++){
      cin>>input[i][j][k];
      if((j+k)%2==0 && input[i][j][k]=='0') even_diff[i]++;
      else if((j+k)%2==0 && input[i][j][k]=='1')odd_diff[i]++;
      else if((j+k)%2==1 && input[i][j][k]=='0') odd_diff[i]++;
      else if((j+k)%2==1 && input[i][j][k]=='1') even_diff[i]++;
    }
  }
  
  int ans = INT_MAX;
  for(int i=0;i<16;i++){
    int temp = 0;
    int num = 0;
    for(int j=0;j<4;j++)
      if(i&(1<<j)){num++;temp += even_diff[j];}
      else temp += odd_diff[j];
    
    if(num!=2)continue;
    ans = min(ans,temp);
  }
  cout<<ans<<endl;
}

