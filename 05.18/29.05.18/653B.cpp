#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define pr pair< int, int >
#define vii vector< vi >

using namespace std;

int main(){
  faster
  int n,q;
  cin>>n>>q;
  vii graph(6);
  
  for(int i= 0;i<q;i++){
    char a,b,c;cin>>a>>b>>c;
    graph[c-'a'].push_back(a-'a');
  }
  
  stack< pr > dfs;
  dfs.push(make_pair(0,1));
  
  int count = 0;
  while(dfs.size()){
    pr top = dfs.top();
    dfs.pop();
    if(top.second==n){ count++;continue;}
    for(int i= 0;i<graph[top.first].size();i++){
      int child = graph[top.first][i];
      dfs.push(make_pair(child,top.second+1));
    }
  }
  cout<<count<<endl;  
  
}
