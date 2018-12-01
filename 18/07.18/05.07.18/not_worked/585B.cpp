#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;


int main(){
  
  int t,n,k;
  cin>>t>>n>>k;
  
  while(t--){
    char input[3][n+1];
    for(int i= 0;i<3;i++)
      for(int j= 1;j<=n;j++) cin>>input[i][j];
    
    
    
    int present[3][n+1],train[3][n+1];
    for(int i = 0;i<3;i++) for(int j=1;j<=n;j++) present[i][j]=0;
      
    for(int i=0;i<3;i++)
      for(int j= 1;j<=n;j++)
        if(2*j-1<=n && input[i][2*j-1] != '.' || ( 2*j-2<=n && 2*j-2>=0&& input[i][2*j-2])) train[i][j] = 1;
        else train[i][j] = 0;

    for(int i = 0;i<3;i++) if(input[i][1] == 's') present[i][1] = 1;
    
    
    for(int i=2;i<=n;i++){
      for(int j= 0;j<3;j++){
        if(train[j][i]) continue;
        if(j-1>=0 && present[j-1][i-1]) present[j][i] = 1;
        if(j+1<3 && present[j+1][i-1]) present[j][i] = 1;
        if(present[j][i-1]) present[j][i] = 1;
      }
    }
    
    for(int i= 0;i<3;i++){
      for(int j= 1;j<=n;j++)cout<<present[i][j]<<" ";
      cout<<endl;
    }
    if(present[0][n] || present[1][n] || present[2][n])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}
