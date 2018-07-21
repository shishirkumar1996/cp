#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define pr pair< int,int >
#define vp vector<  pr >
#define vpp vector< vp >
#define NUM 100007
#define MAXM (lld)(1e9+7)

using namespace std;

vpp graph(NUM);
int n;

void floydWarshall(){
  lld dist[n][n];
  
  for(int i=0;i<n;i++) for(int j=0;j<n;j++)dist[i][j] = MAXM;
  for(int i=0;i<n;i++) dist[i][i]=0;
  
  for(int i=0;i<n;i++)
    for(int j=0;j<graph[i].size();j++)
      dist[i][graph[i][j].first] = graph[i][j].second;   //first vertex second source

  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++) 
        if(dist[i][k]+dist[k][j]<dist[i][j]) dist[i][j] = dist[i][k]+dist[k][j];

  cout<<"Shortest path  matrix is "<<endl;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)cout<<dist[i][j]<<" ";
    cout<<endl;
  }

}

int main(){

  n = 4;
  graph[0].push_back(make_pair(1,5));
  graph[1].push_back(make_pair(0,5));
  graph[0].push_back(make_pair(3,10));
  graph[3].push_back(make_pair(0,10));
  graph[1].push_back(make_pair(2,3));
  graph[2].push_back(make_pair(1,3));
  graph[2].push_back(make_pair(3,1));
  graph[3].push_back(make_pair(2,1));

  floydWarshall();
}
