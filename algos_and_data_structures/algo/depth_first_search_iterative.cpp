#include<bits/stdc++.h>
#define vi vector< int >
#define vii vector< vi >
#define NUM 100007

using namespace std;

vii graph(NUM);
int n,m;

void dfs(){
  
  bool visited[n];
  for(int i=0;i<=n;i++) visited[i] = false;
  
  stack< int > st;
  st.push(1);
  visited[1] = true;
  
  while(st.size()){
    int top = st.top();
    cout<<top<<" ";
    st.pop();
    for(int i=0;i<graph[top].size();i++){
      int child = graph[top][i];
      if(!visited[child]){
        visited[child] = true;
        st.push(child);
      }
    }
  }
  cout<<endl;
}

int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  dfs();
}
