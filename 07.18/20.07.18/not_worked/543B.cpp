#include<bits/stdc++.h>
#define lld long long int
#define vi vector< int >
#define vii vector< vi >

using namespace std;

int main(){
    
  int n,m;
  cin>>n>>m;
  
  vii graph(n+1);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  
  int s1,t1,l1,s2,t2,l2;
  cin>>s1>>t1>>l1>>s2>>t2>>l2;
  int dist1[n+1],dist2[n+1];
  int parent1[n+1],parent2[n+1];
  for(int i=0;i<=n;i++){ dist1[i] = dist2[i] = INT_MAX;parent1[i] = parent2[i] = -1;};
  dist1[s1]  = 0,dist2[s2] = 0;
  
  bool visited[n+1];
  for(int i=0;i<=n;i++) visited[i] = false;

  queue< int > process;
  process.push(s1);
  visited[s1]= true;
  while(process.size()){
    
    int front = process.front();
//    cout<<front<<endl;
    process.pop();
    for(int i=0;i<graph[front].size();i++){
      int child = graph[front][i];
      if(!visited[child]){
        visited[child] = true;
        dist1[child] = dist1[front]+1;
        process.push(child);
        parent1[child] = front;
      }
    }
  }
  for(int i=0;i<=n;i++) visited[i] = false;
  process.push(s2);
  visited[s2] = true;
  while(process.size()){
    int front = process.front();
    process.pop();
    for(int i=0;i<graph[front].size();i++){
      int child = graph[front][i];
      if(!visited[child]){
        visited[child] = true;
        dist2[child] = dist2[front]+1;
        process.push(child);
        parent2[child] = front;
      }
    }
  }
  if(dist1[t1] > l1 || dist2[t2] > l2){
    cout<<-1<<endl;
    return 0;
  }
  set< pair< int,int > > temp;
  int v = t1;
  while(parent1[v] != -1){
    int a = max(parent1[v],v);
    int b = min(parent1[v],v);
    pair< int,int > x = make_pair(a,b);
    temp.insert(x);
    cout<<x.first<<" "<<x.second<<endl;
    v = parent1[v];
  }
  v = t2;
  while(parent2[v] !=-1){
    int a = max(parent2[v],v);
    int b = min(parent2[v],v);
    pair< int,int > x  = make_pair(a,b);
    temp.insert(x);
    cout<<x.first<<" "<<x.second<<endl;
    v = parent2[v];
  }
  
  
  cout<<m-(int)temp.size()<<endl;  
  
}

