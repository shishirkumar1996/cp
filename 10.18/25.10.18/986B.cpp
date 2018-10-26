#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define MAXM 1000007

using namespace std;

vi nex(MAXM);
bool visited[MAXM];

int dfs(int v){
  if(visited[v])return 0;
  visited[v] = true;
  return dfs(nex[v])+1;
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<MAXM;i++)visited[i] = false;
  for(int i=1;i<=n;i++) cin>>nex[i];
  
  int num = 0;
  for(int i=1;i<=n;i++)if(!visited[i]) num += dfs(i)-1;
  if(num%2 == n%2)cout<<"Petr\n";
  else cout<<"Um_nik\n";
}
