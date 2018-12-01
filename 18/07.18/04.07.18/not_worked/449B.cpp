#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld, lld >
#define vi vector< pr >
#define vii vector< vi >
#define MAXM (lld)(1e15+7)

using namespace std;


int main(){
  
  faster
  int n,m,k;
  cin>>n>>m>>k;
  
  int ans = 0;
  vii input(n+1);
  
  map< int, lld > process;
    
  for(int i = 0;i<m;i++){
    int a,b;lld c;
    cin>>a>>b>>c;
    input[a].push_back(make_pair(b,c));
    input[b].push_back(make_pair(a,c));
  }
  
    
  lld dist[n+1];
  bool visited[n+1];


  for(int i = 0;i<=n;i++) dist[i] = MAXM,visited[i] = false;
  priority_queue< pr > temp;
  for(int i = 0;i<k;i++){
    int a;lld b;
    cin>>a>>b;
    temp.push(make_pair(b,a));
    dist[a] = min(dist[a],b);
  }

  temp.push(make_pair(0,1));
  dist[1] = 0;
  
  while(temp.size()){
    pr top = temp.top();
    temp.pop();
    int vertex = top.second;
    if(visited[vertex]){ans++;continue;}
    visited[vertex] = true;
    
    for(int i = 0;i<input[vertex].size();i++){
      pr x = input[vertex][i];
      int child = x.first;
      lld d = x.second;
      if(dist[child]>dist[vertex]+d){
        dist[child] = dist[vertex]+d;
        temp.push(make_pair(dist[child],child));
      }
    }
  }
  
  cout<<ans<<endl; 
}
