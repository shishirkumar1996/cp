#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;

vi topo;
int graph[1001][1001];
bool visited[1001];
int n,k;
void sort(int vertex){
  visited[vertex] = true;
  for(int i = 1;i<=n;i++) if(!visited[i] && graph[vertex][i] == k) sort(i);
  topo.push_back(vertex);
  
}

int main(){
  
  cin>>n>>k;
  
  vii input(k);
  for(int i = 0;i<k;i++)
    for(int j = 0;j<n;j++){
     int a;
     cin>>a;
     input[i].push_back(a);
    }

  for(int i =0;i<=n;i++) visited[i] = false;
  for(int i=0;i<=n;i++) for(int j= 0;j<=n;j++) graph[i][j]= 0;  

  for(int i = 0;i<k;i++)
    for(int x=0;x<n;x++) for(int y =x+1;y<n;y++) graph[input[i][x]][input[i][y]]++;
  
  for(int i= 1;i<=n;i++)if(!visited[i]) sort(i);
  
//  for(int i= 0;i<n;i++) cout<<topo[i]<<" ";cout<<endl;
  int dp[n+1];

  int ans = 0;
  for(int i = 0;i<n;i++){
    dp[topo[i]] = 1;
    for(int j= 0;j<i;j++) 
      if(graph[topo[i]][topo[j]] == k){ 
        dp[topo[i]] = max(dp[topo[i]],dp[topo[j]]+1);
      }
    ans= max(ans,dp[topo[i]]);     
  }
  cout<<ans<<endl;
  
}
