#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define NUM 200007

using namespace std;

bool visited[NUM];
int graph[NUM];

void dfs(int v){
  visited[v]= true;
  if(visited[graph[v]])return;
  dfs(graph[v]);
}

int main(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)cin>>graph[i];
  int sum = 0;
  for(int i=1;i<=n;i++){
    int a;
    cin>>a;
    sum += a;
  }
  int ans = 0;
  if(sum%2==0)ans++;
  
  int num =0;
  for(int i=1;i<=n;i++){
    if(visited[i])continue;
    dfs(i);num++;
  }
  if(num>1) ans += num;
  cout<<ans<<endl;
}
