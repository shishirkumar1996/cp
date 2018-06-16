#include<bits/stdc++.h>

#define lld long long int
#define vi vector< lld >
#define vii vector < vi >

using namespace std;

int calc(int n,vii input){

  bool visited[n+1];
  memset(visited,false,n+1);

  int distance[n+1];
  for(int i = 0;i<=n;i++)
    distance[i] = 0;
    
  stack< pair< lld,lld > > dfs;
  dfs.push(make_pair(1,0));
 
  while(dfs.size()){
    pair< lld,lld > top = dfs.top();
    dfs.pop();
    lld dist,index;
    index = top.first;
    dist = top.second;
    visited[index] = true;
    distance[dist]++;
    
    for(int i=0;i<input[index].size();i++){
      if(visited[input[index][i]])
        continue;
      dfs.push(make_pair(input[index][i],dist+1));
    }
  
  }
  int total = 0;
  for(int i =0;i<=n;i++){
//    cout<<i<<" "<<distance[i]<<endl;
    if(distance[i]%2 != 0)
      total++;
  }
  return total;
}

int main(){
  
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vii input(n+1);
  for(int i = 2;i<=n;i++){
    lld a;
    cin>>a;
    input[i].push_back(a);
    input[a].push_back(i);
  }
  cout<<calc(n,input)<<endl;
}

