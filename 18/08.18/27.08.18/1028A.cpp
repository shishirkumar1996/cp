#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main(){

  faster
  int n,m;
  cin>>n>>m;
  char input[n+1][m+1];
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>input[i][j];

  int first_row,first_col,last_row,last_col;
  for(int i=1;i<=n;i++){
    int flag = 1;
    for(int j=1;j<=m;j++){
      if(input[i][j] == 'B'){first_row = i;first_col=j;flag=0;break;}
    }
    if(!flag)break;
  }
  for(int i=n;i>=1;i--){
    int flag = 1;
    for(int j=m;j>=1;j--)if(input[i][j]=='B'){
    last_row=i;last_col=j;flag=0;break;
    }
    if(!flag)break;
  }
  cout<<(first_row+last_row)/2<<" "<<(first_col+last_col)/2<<endl;
}
