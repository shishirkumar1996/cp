#include<bits/stdc++.h>

#define vi vector< int >
#define vii vector < vi >

using namespace std;

void calc(int n, vii input){
  
  int maxCol = 0;
  for(int i =1;i<input.size();i++)
    if(input[i].size()+1 > maxCol)
      maxCol = input[i].size()+1;
      
  
  int color[n+1];
  int parent[n+1];
  bool visited[n+1];
  memset(visited,false,n+1);
  color[1] = 1,parent[1] = 0;
  parent[0] = 0,color[0] = 0;     // dummy values
  
  stack< pair <int ,int > > dfs;
  dfs.push(make_pair(1,1));
  while(dfs.size()){
    pair <int,int> top = dfs.top();
    dfs.pop();
    int x = top.first;
    int col = top.second;
    color[x] = col;
    visited[x] = true;
    int counter = 1;
    for(int i = 0;i<input[x].size();i++){
      
      int child = input[x][i];
      if(visited[child])
        continue;
      parent[child] = x;
      if(color[parent[child]]== counter||color[parent[parent[child]]]==counter)
        counter++;
      if(color[parent[parent[child]]] == counter||color[parent[child]] == counter)
        counter++;
      dfs.push(make_pair(child,counter));
      counter++;
    }  
  }
  cout<<maxCol<<endl;
  for(int i = 1;i<= n;i++)
    cout<<color[i]<<" ";
  cout<<endl;
}

int main(){

  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vii input;
  input.resize(n+1);
  for(int i = 0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    input[a].push_back(b);
    input[b].push_back(a);
  }
  calc(n,input);
}

