#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< lld >
#define vii vector< vi >
#define pr pair< lld, lld >
#define vp vector< pr >

using namespace std;

int main(){
  
  faster
  int n;
  cin>>n;
  vii input(n+1);
  for(int i = 1;i<n;i++){
    lld a,b;
    cin>>a>>b;
    input[a].push_back(b);
    input[b].push_back(a);
  }
  
  int max_degree =0,count = 0,index;
  for(int i = 1;i<=n;i++){
    if(input[i].size()>max_degree)max_degree = input[i].size(),index=i;
    if(input[i].size()>2)count++;
  
  }
  if(count>1){cout<<"No"<<endl;return 0;}
  
  vp output;
  stack< int > dfs;
  bool visited[n+1];
  for(int i=0;i<=n;i++)visited[i] = false;
  
  dfs.push(index);
  
  while(dfs.size()){
    int top = dfs.top();
    visited[top] = true;
    dfs.pop();
    int flag = 0;
    for(int i =0;i<input[top].size();i++){
      int child = input[top][i];
      if(!visited[child]) flag = 1,dfs.push(child);
    }
    if(!flag) output.push_back(make_pair(index,top));
  }  
  
  cout<<"Yes"<<endl;
  cout<<output.size()<<endl;
  for(int i= 0;i<output.size();i++)
  cout<<output[i].first<<" "<<output[i].second<<endl; 
  
}
