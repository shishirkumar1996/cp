#include<bits/stdc++.h>
#define faster ios::sync_with_stdio(false);cin.tie(0);
#define lld long long int
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int main(){

  int n;
  cin>>n;
  vi input(n+1);
  lld next[n+1];
  
  vii process;
  bool visited[n+1];
  for(int i = 1;i<=n;i++)
    visited[i] = false;
  
  for(int i = 1;i<=n;i++)
    cin>>input[i];
  
  vi mid = input;
  sort(mid.begin()+1,mid.end());
  
  for(int i= 1;i<=n;i++)
    next[i] = (lower_bound(mid.begin()+1,mid.end(),input[i])-mid.begin());
  
  for(int i = 1;i<=n;i++){
    if(visited[i])
      continue;
    
    vi seq;
    stack< lld > dfs;
    dfs.push(i);
    while(dfs.size()){
      lld top = dfs.top();
      seq.push_back(top);
      visited[top] = true;
      dfs.pop();
      
      if(!visited[next[top]])
        dfs.push(next[top]);
      
    }
    process.push_back(seq);
  
  }
  
  cout<<process.size()<<endl;
  for(int i = 0;i<process.size();i++){
    cout<<process[i].size()<<" ";
    for(int j = 0;j<process[i].size();j++)
      cout<<process[i][j]<<" ";
    cout<<endl;
  }

}
