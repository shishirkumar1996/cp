#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define pr pair< lld,lld >
#define vii vector< vi >


using namespace std;

int main(){

  int n,m,s,t;
  cin>>n>>m>>s>>t;
  
  set< pr > process;
  
  vii graph(n+1);
  
  for(int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
    process.insert(make_pair(a,b));
  }
  
  int dist_s[n+1],dist_t[n+1];
  dist_s[s] = 0;
  bool visited[n+1];
  for(int i=0;i<=n;i++) visited[i] = false;
  
  queue< int > temp;
  temp.push(s);
  dist_s[s] = 0;
  visited[s] = true;
  while(temp.size()){
    int top = temp.front();
    temp.pop();
    for(int i= 0;i<graph[top].size();i++){
      int vertex = graph[top][i];
      if(visited[vertex]) continue;
      visited[vertex] = true;
      temp.push(vertex);
      dist_s[vertex] = dist_s[top]+1;
    }
  }
  for(int i = 0;i<=n;i++) visited[i] = false;
  
  temp.push(t);
  visited[t] = true;
  dist_t[t] =  0;
  while(temp.size()){
    int top = temp.front();
    temp.pop();
    for(int i= 0;i<graph[top].size();i++){
      int vertex = graph[top][i];
      if(visited[vertex]) continue;
      visited[vertex] = true;
      temp.push(vertex);
      dist_t[vertex] = dist_t[top]+1;
    }
    
  }
  int ans = 0;
  for(int i= 1;i<n;i++){
    for(int j= i+1;j<=n;j++){
      pr x = make_pair(i,j);
      pr inv_x = make_pair(j,i);
      if(process.count(x) == 1 || process.count(inv_x)==1) continue;
      if(dist_s[i]+dist_t[j]+1< dist_s[t] || dist_t[i]+dist_s[j]+1<dist_s[t])
        continue;
      ans++;
//      cout<<i<<" "<<j<<" "<<dist_s[t]<<" "<<dist_s[i]<<" "<<dist_t[j]<<endl;
    }
  } 
  cout<<ans<<endl;
  
}
