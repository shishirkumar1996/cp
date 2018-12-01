#include<bits/stdc++.h>
#define lld long long int
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector< int >
#define vii vector< vi >
#define NUM 200007

using namespace std;

int order[NUM];

int compare(int a,int b){return order[a]<order[b];}

int main(){

  int n;
  cin>>n;

  vii graph(n+1);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b); graph[b].push_back(b);
  }
  vi process(n);
  for(int i=0;i<n;i++){cin>>process[i];order[process[i]] = i;}

  for(int i=1;i<=n;i++) sort(graph[i].begin(),graph[i].end(),compare);
  
  queue< int > temp;
  bool visited[n+1];
  for(int i=1;i<=n;i++)visited[i] = false;
  
  vi ans;
  temp.push(1);
  visited[1] = true;
  while(temp.size()){
    int front = temp.front();
    ans.push_back(front);
    temp.pop();
    for(int i=0;i<graph[front].size();i++){
      int child = graph[front][i];
      if(visited[child])continue;
      temp.push(child);
      visited[child] = true;
    }
  }
  
  for(int i=0;i<n;i++)if(ans[i] != process[i]){cout<<"No"<<endl;return 0;}
   
  cout<<"Yes"<<endl;
}
