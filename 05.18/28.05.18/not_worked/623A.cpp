#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int main(){
  
  faster
  int n,m;
  cin>>n>>m;
  int input[n+1][n+1];
  for(int i = 0;i<=n;i++)for(int j= 0;j<=n;j++) input[i][j] = 0;
  
  for(int i = 0;i<m;i++){
    int a,b;
    cin>>a>>b;
    input[a][b] = input[b][a] = 1;
  }
  
  char process[n+1];
  for(int i= 1;i<=n;i++){
    int cnt = 0;
    for(int j= 1;j<=n;j++) if(input[i][j]) cnt++;
    if(cnt==n-1) process[i] = 'b'; 
  }
  for(int i = 1;i<=n;i++){
    if(process[i] != 'b'){
      process[i] = 'a';
      for(int j=1;j<=n;j++) if(input[i][j] && process[j] != 'b') process[j] = 'a';
      break;
    }
  }
  for(int i = 1;i<=n;i++) 
    if(process[i] != 'a' && process[i] != 'b') process[i] = 'c';
  
  
  for(int i = 1;i<=n;i++)
    for(int j = 1;j<=n;j++) if((process[i]=='a' && process[j] == 'c')||(process[i] == 'c' && process[j] == 'a')){
      if(input[i][j]){
        cout<<"No"<<endl;
        return 0;
      }
    } else if(i!=j && !input[i][j]){ cout<<"No"<<endl;return 0; }
      
  cout<<"Yes"<<endl;
  for(int i= 1;i<=n;i++)cout<<process[i];
  cout<<endl;

}
