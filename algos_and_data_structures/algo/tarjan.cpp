#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;


int n,timer,m;
vii graph(NUM);
stack< int > st;
vi disc(NUM),low(NUM);
bool stacked[NUM];


void tarjan(int v){
  
  disc[v] = low[v] = ++timer;
  st.push(v);
  stacked[v] = true;
  for(int i=0;i<graph[v].size();i++){
    int child = graph[v][i];
    if(disc[child] ==-1){
      tarjan(child);
      low[v] = min(low[child],low[v]);  
    } else if(stacked[child] == true) low[v] = min(low[v],disc[child]);
  }
  if(low[v]  == disc[v]){
    while(st.top() != v){
      // here is the elements in one scc
      cout<<st.top()<<" ";
      stacked[st.top()] = false;
      st.pop();
    }
    cout<<st.top()<<endl;
    stacked[st.top()] = false;
    st.pop();
  }
}

void initialize(){
  timer = 0;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
  }
  for(int i=0;i<n;i++){
    disc[i] = low[i] = -1;
    stacked[i] = false;
  }
  for(int i=0;i<n;i++) if(disc[i] == -1) tarjan(i);
}


int main(){
  cout<<"Enter the number of vertices and edges"<<endl;
  cin>>n>>m;
  initialize();
}
