#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< lld >
#define vii vector< vi >


using namespace std;


int main(){


  faster
  int n,m;
  cin>>n>>m;
  vii input(n+1);
  for(int i=0;i<m;i++){
    lld a,b;
    cin>>a>>b;
    input[a].push_back(b);
    input[b].push_back(a);
  }
  
  bool visited[n+1];
  for(int i =0;i<=n;i++) visited[i] = false;
  
  
  int cycles = 0;
  for(int i = 1;i<=n;i++){
    
    int flag = 1;
    if(visited[i])
      continue;
    if(input[i].size() != 2)
      flag = 0;
    
    stack< lld > dfs;
    dfs.push(i);
    while(dfs.size()){
      
      int top  = dfs.top();
//      cout<<top<<" "<<flag<<endl;
      visited[top] = true;
      dfs.pop();
      for(int j = 0;j<input[top].size();j++){
        lld child = input[top][j];
        if(input[child].size() != 2) flag = 0;
        if(!visited[child]) dfs.push(child);
      }  
    }
    if(flag)
      cycles++;
  }
  cout<<cycles<<endl;
}
