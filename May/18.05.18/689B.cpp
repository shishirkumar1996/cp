#include<bits/stdc++.h>
#define lld long long int
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define pr pair< lld ,lld >
#define vi vector< lld >
#define vii vector< vi >

using namespace std;

int main(){

  faster
  int n;
  cin>>n;
  
  vii input(n+1);
  for(int i = 1;i<=n;i++)  {
    if(i<n) input[i].push_back(i+1);
    if(i>1) input[i].push_back(i-1);
  }
  
  for(int i = 1;i<=n;i++){
    lld a;
    cin>>a;
    input[i].push_back(a);
  }
  
  lld dist[n+1];
  for(int i = 0;i<=n;i++) dist[i] = INT_MAX;
 
  dist[1] = 0;  
  
  bool visited[n+1];
  priority_queue< pr > ans;
  
  ans.push(make_pair(0,1));
  while(ans.size()){
    
    pr top = ans.top();
    ans.pop();
    lld point = top.second;
    for(int i = 0;i<input[point].size();i++){
      lld child = input[point][i];
      if(dist[child] > dist[point]+1){
        dist[child] = dist[point]+1;
        ans.push(make_pair(dist[child],child));
      }
    }
  
  }
  
  for(int i = 1;i<=n;i++) cout<<dist[i]<<" ";
  cout<<endl;

}
