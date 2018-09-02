#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int main(){

  int n;
  cin>>n;
  vii graph(n+1);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b); graph[b].push_back(a);
  }
  
  int parent[n+1];
  bool taken[n+1];
  for(int i=0;i<=n;i++) taken[i] = false;
  
  for(int i=1;i<=n;i++)parent[i]= 0;
  queue< int > process;
  process.push(1);
  while(process.size()){
    int front =process.front();
    process.pop();
    for(int i=0;i<graph[front].size();i++){
      int child = graph[front][i];
      if(child==parent[front])continue;
      parent[child] = front;
      process.push(child);
    }
  }
 
  int counter[n+1];
  for(int i=0;i<=n;i++)counter[i] = 0;
  
  int max_counter = 1;
  counter[1] = 1; 
  vi temp(n);
  for(int i=0;i<n;i++)cin>>temp[i];
  
  taken[0] = true;
  for(int i=0;i<n;i++){
    cout<<temp[i]<<" "<<counter[temp[i]]<<endl;
    if(counter[temp[i]]<max_counter){ cout<<"No"<<endl;return 0; }
    else if(counter[temp[i]]>=max_counter){
      max_counter = counter[temp[i]];
      for(int j=0;j<graph[temp[i]].size();j++){
        int child = graph[temp[i]][j];
        if(counter[child])continue;
        counter[child] = max_counter+1;
      }
    }
  }
  cout<<"Yes"<<endl; 
}
