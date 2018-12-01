#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;


int main(){

  faster
  int n,m;
  cin>>n>>m;
  vi input(n+1);
  vii graph(n+1);
  for(int i=1;i<=n;i++)cin>>input[i];
  for(int i=1;i<=m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  bool visited[n+1];
  for(int i=0;i<=n;i++)visited[i] = false;
  
  for(int i=1;i<=n;i++){
    if(visited[i])continue;
    vi pos,num;
    stack< int > process;
    process.push(i);
    visited[i] = true;
    while(process.size()){
      int top = process.top();
      process.pop();
      pos.push_back(top);
      num.push_back(input[top]);
      for(int i=0;i<graph[top].size();i++){
        int child = graph[top][i];
        if(visited[child])continue;
        visited[child] = true;
        process.push(child);
      }
    }
    sort(pos.begin(),pos.end());
    sort(num.begin(),num.end());
    reverse(num.begin(),num.end());
    for(int i=0;i<pos.size();i++){
      input[pos[i]] = num[i];
    }
  }
  for(int i=1;i<=n;i++)cout<<input[i]<<" ";
  cout<<endl; 
}
