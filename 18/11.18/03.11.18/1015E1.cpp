#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vs vector< string >
#define pr pair< int,int >
#define ppr pair< pr, int >
#define vp vector< ppr >
#define trace(x) cerr<<#x<<": "<<x<<'\n';
#define trace2(a,n) cerr<<#a<<": ";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<'\n';

using namespace std;

int main(){
  
  int n,m;
  cin>>n>>m;
  
  char input[n+2][m+2];
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>input[i][j];
  
  bool reached[n+2][m+2];
  for(int i=0;i<=n+1;i++)for(int j=0;j<=m+1;j++) reached[i][j] = false;
  
  vp output;
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
    if(input[i][j] != '*')continue;
    int flag = 1;
    int k = 1;
    while(flag){
      if(input[i-k][j] == '*' && input[i+k][j]=='*' && input[i][j-k] == '*' && input[i][j+k] == '*'){ 
      reached[i-k][j] = reached[i+k][j] = reached[i][j-k] = reached[i][j+k] = true;
      k++;
      }
      else flag = 0;
    }
    k--;
    if(k){ reached[i][j] = true;
    output.push_back(make_pair(make_pair(i,j),k)); }
  }
  int flag = 1;
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    if(input[i][j]=='*' && !reached[i][j]) flag = 0;
    
  if(!flag){ cout<<-1<<'\n'; return 0;}
  cout<<output.size()<<'\n';
  for(int i=0;i<output.size();i++)
    cout<<output[i].first.first<<" "<<output[i].first.second<<" "<<output[i].second<<'\n';
}
