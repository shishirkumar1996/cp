#include<bits/stdc++.h>
#define lld long long int
#define vi vector < lld >
#define vii vector < vi >
#define pr pair< lld, lld >
#define vp vector < pr >
#define vip vector < vp >
#define MAXM 100000000000


using namespace std;

void print_path(int num,int parent[]){
  
  if(parent[num] != num)
    print_path(parent[num],parent);
  cout<<num<<" ";

}


void calc(int n,int m, vip input){
  
  int parent[n+1];
  memset(parent,-1,n+1);
  
  parent[1] = 1;
  lld dist[n+1];
  bool visited[n+1];
  for(int i = 0;i<=n;i++)
    dist[i] = MAXM;

  memset(visited,false,n+1);
  dist[1] = 0;
  
  priority_queue< pr ,vector< pr >,std::greater< pr > > pq;
  
  pq.push(make_pair(dist[1],1));
  while(pq.size())
  {
    pr top = pq.top();
//    cout<<top.first<<" "<<top.second<<endl;
    visited[top.second] = true;
    pq.pop();
//    cout<<input[top.second].size()<<endl;    
    for(int i = 0;i<input[top.second].size();i++){
      int vertex = input[top.second][i].first;
      if(visited[vertex] == true)
        continue;
      
//      cout<<vertex<<" "<<dist[vertex]<<" "<<dist[top.first]<<" "<<input[top.second][i].second<<endl;
      if(dist[vertex] > top.first + input[top.second][i].second){
        dist[vertex] = top.first + input[top.second][i].second;
        parent[vertex] = top.second;
        pq.push(make_pair(dist[vertex],vertex));
//        cout<<dist[vertex]<<endl;
      }

    }
   
  }
  if(dist[n]==MAXM){
    cout<<"-1"<<endl;
    return;
  } 
   
  print_path(n,parent);
  cout<<endl;

}

int main(){

  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  vip input;
  input.resize(n+1);
  for(int i = 0;i<m;i++){
    lld x,y,dist;
    cin>>x>>y>>dist;
    input[x].push_back(make_pair(y,dist));
    input[y].push_back(make_pair(x,dist));
  
  }

  calc(n,m,input);
}


