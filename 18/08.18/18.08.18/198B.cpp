#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define NUM 100007

using namespace std;

vector< string >input(2);
int n,k;
bool visited[2][NUM];


int dfs(int row,int col,int t){
  
//  cout<<col<<" "<<row<<" "<<t<<" "<<input[col][row]<<endl;
  if(row<=t)return 0;
  if(row>=n) return 1;
  if(input[col][row]=='X')return 0;
  if(visited[col][row]) return 0;
  visited[col][row] = true;
  
  return dfs(row-1,col,t+1)||dfs(row+k,col^1,t+1)||dfs(row+1,col,t+1);
}



int main(){
  
  faster
  cin>>n>>k;
  for(int i=0;i<2;i++)cin>>input[i];

  for(int i=0;i<n;i++)visited[0][i] = visited[1][i] = false;
  int ans = dfs(0,0,-1);
  if(ans)cout<<"YES"<<endl; else cout<<"NO"<<endl;
}
